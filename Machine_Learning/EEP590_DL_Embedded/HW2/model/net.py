"""Defines the neural network, loss function and metrics"""

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F


class Net(nn.Module):
    """
    This is the standard way to define your own network in PyTorch. You typically choose the components
    (e.g. LSTMs, linear layers etc.) of your network in the __init__ function. You then apply these layers
    on the input step-by-step in the forward function. You can use torch.nn.functional to apply functions
    such as F.relu, F.sigmoid, F.softmax. Be careful to ensure your dimensions are correct after each step.

    The documentation for all the various components available to you is here: http://pytorch.org/docs/master/nn.html
    """

    def __init__(self, params):
        """
        We define an recurrent network that predicts the tags for each token in the sentence. The components
        required are:

        - an embedding layer: this layer maps each index in range(params.vocab_size) to a params.embedding_dim vector
        - lstm: applying the LSTM on the sequential input returns an output for each token in the sentence
        - fc: a fully connected layer that converts the LSTM output for each token to a distribution over tags

        Args:
            params: (Params) contains vocab_size, embedding_dim, lstm_hidden_dim
        """
        super(Net, self).__init__()

        # the embedding takes as input the vocab_size and the embedding_dim
        self.embedding = nn.Embedding(params.vocab_size, params.embedding_dim) # TODO [ hint: use nn.Embedding() ]

        # the LSTM takes as input the size of its input (embedding_dim), its hidden size
        # for more details on how to use it, check out the documentation
        self.lstm = nn.LSTM(params.embedding_dim, params.lstm_hidden_dim, batch_first=True)# TODO

        # the fully connected layer transforms the output to give the final output layer
        self.fc = nn.Linear(params.lstm_hidden_dim, params.number_of_tags) # TODO

    def forward(self, s):
        """
        This function defines how we use the components of our network to operate on an input batch.

        Args:
            s: (Variable) contains a batch of sentences, of dimension batch_size x seq_len, where seq_len is
               the length of the longest sentence in the batch. For sentences shorter than seq_len, the remaining
               tokens are padding tokens. Each row is a sentence with each element corresponding to the index of
               the token in the vocab.

        Returns:
            out: (Variable) dimension batch_size*seq_len x num_tags with the log probabilities of tokens for each token
                 of each sentence.

        Note: the dimensions after each step are provided
        """
        #                                -> batch_size x seq_len
        # apply the embedding layer that maps each token to its embedding
        # dim: batch_size x seq_len x embedding_dim
        s = self.embedding(s)# TODO

        # run the LSTM along the sentences of length seq_len
        # dim: batch_size x seq_len x lstm_hidden_dim
        s, _ = self.lstm(s)# TODO

        # make the Variable contiguous in memory (a PyTorch artefact)
        s = s.contiguous()# TODO

        # reshape the Variable so that each row contains one token
        # dim: batch_size*seq_len x lstm_hidden_dim
        s = s.view(-1, s.shape[2])# TODO

        # apply the fully connected layer and obtain the output (before softmax) for each token
        s = self.fc(s)# TODO                    dim: batch_size*seq_len x num_tags

        # apply log softmax on each token's output (this is recommended over applying softmax
        # since it is numerically more stable)
        output = F.log_softmax(s, dim=1)# TODO
        return output   # dim: batch_size*seq_len x num_tags


def loss_fn(outputs, labels):
    """
    Compute the cross entropy loss given outputs from the model and labels for all tokens. Exclude loss terms
    for padding tokens.

    Args:
        outputs: (Variable) dimension batch_size*seq_len x num_tags - log softmax output of the model
        labels: (Variable) dimension batch_size x seq_len where each element is either a label in [0, 1, ... num_tag-1],
                or -1 in case it is a padding token.

    Returns:
        loss: (Variable) cross entropy loss for all tokens in the batch

    Note: you may use a standard loss function from http://pytorch.org/docs/master/nn.html#loss-functions. This example
          demonstrates how you can easily define a custom loss function.
    """

    # reshape labels to give a flat vector of length batch_size*seq_len
    labels = labels.view(-1)

    # since padding tokens have label -1, we can generate a mask to exclude the loss from those terms
    mask = (labels >= 0).float()

    # indexing with negative values is not supported. Since PADded tokens have label -1, we convert them to a positive
    # number. This does not affect training, since we ignore the PADded tokens with the mask.
    labels = labels % outputs.shape[1]

    num_tokens = int(torch.sum(mask))

    # compute cross entropy loss for all tokens (except padding tokens), by multiplying with mask.
    loss = -torch.sum(outputs[range(outputs.shape[0]), labels]*mask)/num_tokens # TODO
    return loss


def accuracy(outputs, labels):
    """
    Compute the accuracy, given the outputs and labels for all tokens. Exclude padding terms.

    Args:
        outputs: (np.ndarray) dimension batch_size*seq_len x num_tags - log softmax output of the model
        labels: (np.ndarray) dimension batch_size x seq_len where each element is either a label in
                [0, 1, ... num_tag-1], or -1 in case it is a padding token.

    Returns: (float) accuracy in [0,1]
    """

    # reshape labels to give a flat vector of length batch_size*seq_len
    labels = labels.ravel()

    # since padding tokens have label -1, we can generate a mask to exclude the loss from those terms
    mask = (labels >= 0)

    # np.argmax gives us the class predicted for each token by the model
    outputs = np.argmax(outputs, axis=1)

    # compare outputs with labels and divide by number of tokens (excluding padding tokens)
    acc = np.sum(outputs == labels)/float(np.sum(mask)) # TODO
    return acc


# maintain all metrics required in this dictionary- these are used in the training and evaluation loops
metrics = {
    'accuracy': accuracy,
    # could add more metrics such as accuracy for each token type
}
