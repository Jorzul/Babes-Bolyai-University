import socket
import threading
import time

if __name__ == '__main__':
    done = False

    try:
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        udp_socket.bind(('127.0.0.1', 7131))
    except socket.error as msg:
        print(msg.strerror)
        exit(-1)

    try:
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        tcp_socket.bind(('127.0.0.1', 1234))
    except socket.error as msg:
        print("Error: ", msg.strerror)
        exit(-1)

    pi_aprox = float(0)
    period = int(0)

    end_iterating_number = int(12)
    iterating_number = int(0)

    while not done:
        #message = 'hello'
        #rs.sendto(message.encode(), ('127.255.255.255', 7131))
        #print("sent message!")
        #time.sleep(2)
        msg = udp_socket.recvfrom(1024)
        msg2 = udp_socket.recvfrom(1024)

        int_msg = float( (50 - int(msg[0].decode()) ) / 100)
        int_msg2 = float( (50 - int(msg2[0].decode()) ) / 100)

        print("Numbers: ", int_msg, " ", int_msg2)

        msgs_avg = float( ( int_msg + int_msg2 ) / 2 )
        pi_aprox = float( ( pi_aprox + msgs_avg ) / 2 )

        print("Pi Approximation: ", pi_aprox)

        if period == 3:

            tcp_socket.sendto(str(pi_aprox).encode(), ('127.255.255.255', 1234))
            period = int(0)

        period += 1
        iterating_number += 1

        if iterating_number == end_iterating_number:
            print("Number of iterations achieved: ")
            print("Final Pi approximation: ", pi_aprox)
            print("Exiting program..")
            tcp_socket.sendto(str(pi_aprox).encode(), ('127.255.255.255', 1234))
            done = True
