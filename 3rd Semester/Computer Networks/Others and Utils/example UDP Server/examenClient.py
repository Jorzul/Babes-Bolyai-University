import random
import socket
import time

if __name__ == '__main__':
    try:
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        udp_socket.bind(('127.0.0.1', 7131))
    except socket.error as msg:
        print("Error: ", msg.strerror)
        exit(-1)

    try:
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        tcp_socket.bind(('127.0.0.1', 1234))

    except socket.error as msg:
        print("Error: ", msg.strerror)
        exit(-1)

    N = int(4)
    period = 0

    for _ in range(0, 2*N):
        #msg = rs.recvfrom(1024)
        #print(msg[0].decode())
        random_number1 = str(random.randint(1, 100))
        random_number2 = str(random.randint(1, 100))
        udp_socket.sendto(random_number1.encode(), ('127.255.255.255', 7131))
        udp_socket.sendto(random_number2.encode(), ('127.255.255.255', 7131))
        print("sent message!")
        time.sleep(1)

        if period == 3:
            msg = tcp_socket.recvfrom(1024)
            print(msg[0].decode())
            period = 0
        period += 1

    print("All 2*N numbers were sent")