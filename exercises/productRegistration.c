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
	unsigned int index_first;
	unsigned int index_last;
} ProductList;

// Proc. adicionar produto
void add_product(ProductList product_list, char *description, double price, unsigned int quantity) {
	if (product_list.num_products == 0) {
		Product new_product = { 1, description, price, quantity };
		product_list.products = malloc(sizeof(Product) * 1);
		product_list.products[0] = new_product;
		product_list.num_products++;
		product_list.index_first = 0;
		product_list.index_last = 0;
	} else {
		Product new_product = {
			product_list.num_products,
			description,
			price,
			quantity
		};
		realloc(product_list.products, sizeof(product_list.products) + sizeof(Product));
		product_list.products[product_list.index_last] = new_product;
		product_list.index_last++;
		product_list.num_products++;
	}
}

// Proc. exibir lista completa de produtos
void print_all_products(ProductList product_list) {
	printf("LISTA DE PRODUTOS\n");
	Product *p = product_list.products;
	size_t length = sizeof(p) / sizeof(Product);
	for (unsigned int i = 0; i < length; i++) {
		printf("%u", p[i].id);
		printf("%s", p[i].description);
		printf("%.2f", p[i].price);
		printf("%u\n", p[i].quantity);
	}
}

// Modulo principal
int main() {
	ProductList products;
	add_product(products, "Pizza", 5.00, 2);
	add_product(products, "Pão", 2.00, 2);

	print_all_products(products);
	
	free(products.products);

	return 0;
}

