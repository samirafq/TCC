import socket

local_ip = "0.0.0.0"
local_port = 1234


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((local_ip, local_port))

print("Aguardando a mensagem UDP")

while True:
    data, addr = sock.recvfrom(1024)
    print(f"Mensagem recebida {addr}: {data.decode}")