- [Ethernet](#ethernet)
  - [UDP/TCP](#udptcp)
    - [TCP/IP](#tcpip)

# Ethernet

## UDP/TCP
TCP (Transmission Control Protocol)和UDP(User Datagram Protocol)协议属于传输层协议。其中TCP提供IP环境下的数据可靠传输，它提供的服务包括数据流传送、可靠性、有效流控、全双工操作和多路复 用。通过面向连接、端到端和可靠的数据包发送。通俗说，它是事先为所发送的数据开辟出连接好的通道，然后再进行数据发送；而UDP则不为IP提供可靠性、 流控或差错恢复功能。一般来说，TCP对应的是可靠性要求高的应用，而UDP对应的则是可靠性要求低、传输经济的应用。 TCP支持的应用协议主要有：Telnet、FTP、SMTP等； UDP支持的应用层协议主要有：NFS（网络文件系统）、SNMP（简单网络管理协议）、DNS（主域名称系统）、TFTP（通用文件传输协议）等。 TCP/IP协议与低层的数据链路层和物理层无关，这也是TCP/IP的重要特点

**TCP(Transmission Control Protocol)**
- 传输控制协议
- 可靠的、面向连接的协议
- 传输效率低
**UDP(User Datagram Protocol)**
- 用户数据报协议
- 不可靠的、无连接的服务
- 传输效率高

UDP（User Datagram Protocol）和TCP（Transmission Control Protocol）是两种传输层协议，它们共同构成了因特网协议套件（Internet Protocol Suite）中的传输层。

主要区别包括：

1. **连接性：**
   - TCP是面向连接的协议，提供可靠的、有序的数据传输。在通信前需要建立连接，数据传输完毕后需要断开连接。
   - UDP是无连接的协议，不进行连接的建立和断开。每个数据包（数据报）在发送时都是独立的，接收端独立处理每个数据包。

2. **可靠性：**
   - TCP提供可靠性传输，确保数据的完整性和有序性。它会重新发送丢失或错误的数据，保证数据的正确到达。
   - UDP不提供可靠性传输，数据包可能会丢失或无序到达。它更注重实时性和简洁性。

3. **流控制和拥塞控制：**
   - TCP具有流控制和拥塞控制机制，以防止发送端发送速率过快，导致网络拥塞。
   - UDP没有流控制和拥塞控制，因此适用于那些对实时性要求较高、能够容忍一些数据丢失的应用。

4. **应用场景：**
   - TCP通常用于对数据准确性要求高、需要按序传输的应用，如文件传输、网页浏览等。
   - UDP适用于对实时性要求高、能够容忍一些数据丢失的应用，如音频、视频、在线游戏等。

总体而言，TCP和UDP在不同的应用场景下各有优势，选择使用哪种取决于具体的需求和应用特点。

### TCP/IP

TCP/IP (Transmission Control Protocol/Internet Protocol):传输控制协议和网络协议是用于因特网 (Internet) 的通信协议。

TCP (Transmission Control Protocol)和 UDP(User Datagram Protocol)协议属于传输层协议。