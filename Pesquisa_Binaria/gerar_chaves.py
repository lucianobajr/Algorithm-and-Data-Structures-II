import random
t=int(input("Digite a quantidade de itens no arquivo:"))
arq=open("%d.txt"%t,"w")
chave=[random.randint(0,50)for i in range(t)]
arq.write("%d\n"%t)
for i in range(t):
    arq.write("%d \n"%(chave[i]))
arq.close()