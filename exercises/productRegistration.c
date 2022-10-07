/* Programa para cadastrar, consultar e remover produtos.
 * Exercício para praticar programação modular estrutura
 * de dados. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
	unsigned int id;
	char *description;
	double price;
	unsigned int quantity;
} Product;

typedef struct ProductList {
	Product *products;
	unsigned int num_products;
	unsigned int index_last;
} ProductList;

// Proc. adicionar produto à lista de produtos
void add_product(ProductList *product_list, Product product) {
	if (product_list->num_products == 0) {
		product.id = product_list->num_products + 1;
		product_list->products = malloc(sizeof(Product) * (product_list->num_products + 1));
		product_list->products[0] = product;
		product_list->num_products++;
		product_list->index_last = 0;
	} else {
		product.id = product_list->num_products + 1;
		realloc(product_list->products, sizeof(Product) * (product_list->num_products + 1));
		product_list->index_last++;
		product_list->products[product_list->index_last] = product;
		product_list->num_products++;
	}
}

// Proc. exibir todos os produtos da lista de produtos
void print_products(ProductList *product_list) {
	unsigned int length = product_list->num_products;
	printf("LISTA DE PRODUTOS\n");
	for (unsigned int i = 0; i < length; i++) {
		printf("%u - ", product_list->products[i].id);
		printf("%s\t\t", product_list->products[i].description);
		printf("%.2f\t ", product_list->products[i].price);
		printf("%u\n", product_list->products[i].quantity);
	}
}

// Func. inicializa lista de produtos
ProductList init_list() {
	ProductList product_list = {
		NULL,
		0,
		NULL
	};
	return product_list;
}

// Func. criar produto
Product create_product(char * description, double price, unsigned int quantity) {
	Product product = {
		NULL,
		description,
		price,
		quantity
	};
	return product;
}

// Modulo principal
int main() {
	ProductList products = init_list();
	add_product(&products, create_product("Pão", 0.1, 2));
	add_product(&products, create_product("Leite", 0.1, 2));
	add_product(&products, create_product("Arroz", 0.1, 2));
	add_product(&products, create_product("Feijão", 0.1, 2));
	print_products(&products);
	return 0;
}

