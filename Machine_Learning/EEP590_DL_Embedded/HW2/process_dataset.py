"""Read, split and save the kaggle dataset for our model"""

import csv
import os
import sys
from numpy import seterrobj

import pandas as pd


def load_dataset(path_csv):
    """(TODO) Loads dataset into memory from csv file"""

    data_df = pd.read_csv(path_csv, encoding = 'unicode_escape')

    dataset = []

    words, tags = [], []

    for i in range(1, len(data_df)):
        word, tag = data_df.at[i,'Word'], data_df.at[i,'Tag']
        if pd.notna(data_df.at[i,'Sentence #']):
            if words:
                dataset.append([words, tags])
                words, tags = [], []

        word, tag = str(word), str(tag)
        if word and not word.isspace():
            words.append(word)
            tags.append(tag)

            
    return dataset


def save_dataset(dataset, save_dir):
    """ (TODO) Writes sentences.txt and labels.txt files in save_dir from dataset
    See data/example for the format

    Args:
        dataset: ([(["a", "cat"], ["O", "O"]), ...])
        save_dir: (string)
    """
    # (TODO) Create directory if it doesn't exist
    if not os.path.exists(save_dir):
        os.makedirs(save_dir)

    # (TODO) Export the dataset
    with open(os.path.join(save_dir, 'sentences.txt'), 'w') as sentences_file:
        with open(os.path.join(save_dir, 'labels.txt'), 'w') as tags_file:
            for sentences, tags in dataset:
                sentences_file.write("{}\n".format(" ".join(sentences)))
                tags_file.write("{}\n".format(" ".join(tags)))


    print(" Done ")


if __name__ == "__main__":
    # Check that the dataset exists (you need to make sure you haven't downloaded the `ner.csv`)
    path_dataset = 'data/new_data/dataset.csv'

    # Load the dataset into memory
    print("Loading dataset into memory...")
    dataset = load_dataset(path_dataset)
    print(" Done ")

    # Split the dataset into train, val and split (dummy split with no shuffle)
    train_dataset = dataset[:int(0.7*len(dataset))]# TODO
    val_dataset = dataset[int(0.7*len(dataset)) : int(0.9*len(dataset))]# TODO
    test_dataset = dataset[int(0.9*len(dataset)):]# TODO

    # Save the datasets to files
    save_dataset(train_dataset, 'data/new_data/train')
    save_dataset(val_dataset, 'data/new_data/val')
    save_dataset(test_dataset, 'data/new_data/test')