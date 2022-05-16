import math

def funcao(x):
  
  f = (math.sin(2*x) + 4*x*x + 3*x)**2
  return f

def abordagem_fechada(xi, xf):
  
  h = (xf - xi)/4
  a = [7, 32, 12, 32, 7]
  k = 0.0

  for i in range(len(a)):
    k += funcao(xi+i*h)*a[i]

  alt = (2*h*k)/45
  return alt
    
def abordagem_aberta(xi, xf):

  h = (xf - xi)/6
  a = [33, 42, 78, 42, 33]
  k = 0

  for i in range(len(a)):
    k += funcao((xi+h)+i*h)*a[i]

  alt = (3*h*k)/10
  return alt

def particao(xi, xf, n, f):
  dx = (xf - xi)/n
  k = 0.0
  for i in range(n):
    a = xi+i*dx
    b = a+dx
    if (f == 1):
      k += abordagem_fechada(a,b)
    else:
      k += abordagem_aberta(a,b)
    
  return k

def main():
  
  print("Polinômio de grau 4\n")
  print("Trabalhando com tolerância de 10 elevado a menos 6\n")
  xi = int(input("Digite um número para xi: \n" ))
  xf = int(input("Digite um número para xf: \n" ))
  filoUsada = int(input("Digite 1 para Filosofia Fechada e 2 para Filosofia Aberta\n"))
  n = int(input("Número de intervalos que deseja particionar:\n"))
  
  if filoUsada == 1:
    f = 1
  elif filoUsada == 2:
    f = 2
  
  print(f'Resultado sem a tolerância: {particao(xi, xf, n, f)}')
  
  n = 1
  intAntiga = particao(xi, xf, n, f)
  cont = 0
  
  while True:
    n += 2
    intAtual = particao(xi, xf, n, f)
    erro = abs((intAtual - intAntiga) / intAtual)
    intAntiga = intAtual
    cont += 1
    if (erro > 0.000001):
      break;
  
  print("Resultado com tolerância: {} \n".format(intAtual))
  print("Iterações: {} \n".format(cont))
  print("Abordagem fechada: \n", abordagem_fechada(xi, xf))
  print("Abordagem aberta: \n",abordagem_aberta(xi, xf))
  
main()