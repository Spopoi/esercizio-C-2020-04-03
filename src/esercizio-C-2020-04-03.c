#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 64
#define PHONE_LEN 20
int idProgressivo = 1;

typedef struct {
	int id; // id numerico del contatto (valore univoco)
	char name[NAME_LEN + 1]; // nome della persona
	char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

contact_type* create_contact(char *name, char *phone) {
	contact_type *result = malloc(sizeof(contact_type));
	for (int i = 0; i < NAME_LEN; i++) {
		result->name[i] = name[i];
	}
	for (int j = 0; j < PHONE_LEN; j++) {
		result->phone[j] = phone[j];
	}
	result->id = idProgressivo;
	idProgressivo++;
	return result;
}

void print_contact(contact_type *person) {
	printf("person: id=%d, name='%s', phone='%s'\n", person->id, person->name,
			person->phone);
}

int main(int argc, char *argv[]) {

	contact_type *pino = create_contact("pino rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type *gino = create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);

	return 0;
}
