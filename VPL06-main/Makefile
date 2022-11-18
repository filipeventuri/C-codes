CC := g++
FLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: main
    
main: util venda
	$(CC) $(FLAGS) $(BUILD)/*.o src/main.cpp  -o main.out
    
util: 
	$(CC) $(FLAGS) -c src/util.cpp -o build/util.o

venda: pedido
	$(CC) $(FLAGS) -c src/venda.cpp -o build/venda.o

pedido: produto acai cachorro_quente pizza
	$(CC) $(FLAGS) -c src/pedido.cpp -o build/pedido.o

produto: 
	$(CC) $(FLAGS) -c src/produto.cpp -o build/produto.o

acai: 
	$(CC) $(FLAGS) -c src/acai.cpp -o build/acai.o

cachorro_quente: 
	$(CC) $(FLAGS) -c src/cachorro_quente.cpp -o build/cachorro_quente.o

pizza:
	$(CC) $(FLAGS) -c src/pizza.cpp -o build/pizza.o

clean:
	$(RM) -r $(BUILD)/* $(TARGET)