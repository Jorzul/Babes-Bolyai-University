import socket
import threading
import time

if __name__ == '__main__':
    try:
        rs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        rs.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        rs.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        rs.bind(('127.0.0.1', 7131))
    except socket.error as msg:
        print(msg.strerror)
        exit(-1)

    while True:
        message = 'hello'
        rs.sendto(message.encode(), ('127.255.255.255', 7131))
        print("sent message!")
        time.sleep(2)
