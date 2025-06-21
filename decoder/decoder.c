#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// {} зона видимости
// первые 8 символов название сообщения (на него можно ссылаться)
// размер в символах (в шестнадцатеричной системе)
// название отправляющей программы
// название принимающей программы
// ! ошибка (код ошибки на той-же строке в шестнадцатеричной системе)
// * состояние программы F|E|W|R (fatal, error, wait, running) 
// 	*F-R можно на той-же строке написать действие (перезапустить программу)
// 	*R-notify (пример приминения)
// - действие (на той-же строке пишется действие)
//	-R перезапустить программу
//	-R=arg0;arg1;arg2 перезапустить программу с аргументами
//	-notify после исправления проблем записать сообщение мол всё исправлено
// [\] конец файла






void u8_to_hex( char *result, const uint8_t x ) {
	uint8_t x1 = ( x % 16 );
	uint8_t x2 = ( (x/16) % 16 );
	if ( x2 <= 9 ) { result[0] = x2+48; }
	if ( x1 <= 9 ) { result[1] = x1+48; }
	if ( x2 > 9 ) { result[0] = x2+87; }
	if ( x1 > 9 ) { result[1] = x1+87; }
	result[2] = '\0';
}




char* encoder( const char const *program_name, const char const *recipient_program, const char const *state, const int return_code, const char const *action, char *encoded_str ) {
	uint8_t len[3] = {0,0,0};
	char hex_table[9];
	char hex_len[3];
	char hex_len2[3];
	char hex_len3[3];
	char hex_code[3];

	len[0] = strlen( program_name );
	len[1] = strlen( recipient_program );
	len[2] = strlen( action );
	printf("len = %d\n", len[0]);
	printf("len2 = %d\n", len[1]);
	printf("len3 = %d\n", len[2]);

	u8_to_hex( hex_len, len[0] );
	u8_to_hex( hex_len2, len[1] );
	u8_to_hex( hex_len3, len[2] );

	u8_to_hex( hex_code, return_code );
	printf("hex_code = %s\n", hex_code);

	printf("hex_len = %s\n", hex_len);
	printf("hex_len2 = %s\n", hex_len2);
	printf("hex_len3 = %s\n", hex_len3);

	for ( uint8_t i = 0; i < strlen(hex_len); i++ ) {
		hex_table[i] = hex_len[i];
	}
	hex_table[ strlen(hex_len) ] = ';';

	for ( uint8_t i = 0; i < strlen(hex_len2); i++ ) {
		hex_table[ i + strlen(hex_len) + 1 ] = hex_len2[i];
	}
	hex_table[ strlen(hex_len) + strlen(hex_len2) + 1 ] = ';';

	for ( uint8_t i = 0; i < strlen(hex_len3); i++ ) {
		hex_table[ i + strlen(hex_len) + strlen(hex_len2) + 2 ] = hex_len3[i];
	}
	hex_table[ strlen(hex_len) + strlen(hex_len2) + strlen(hex_len3) + 2 ] = '\0';

	printf("hex_table = %s\n", hex_table);


	sprintf(encoded_str, "{%s\n%s\n&%s\n*%s\n!%s\n-%s\n}", hex_table, program_name, recipient_program, state, hex_code, action);


	printf("encoded_str = \n%s\n", encoded_str);

	return encoded_str;
}


int main( const int argc, const char const *argv[] ) {
	const char prog_name[8] = "program\0";
	const char recipient_prog_name[7] = "helper\0";
	const char state[10] = "R-notify\0";
	const int return_code = 127;
	const char action[3] = "CD\0";
	//char buff[255] = "{7;6;3;9;f1\nprogram\nhelper\n!7f\n*W-R=arg1\nopqwertyuiopqwertyuiopqwertyuiopf}\n[\\]";
	char buffer[255];

	encoder( prog_name, recipient_prog_name, state, return_code, action, buffer );



	//printf("\033[2mbuff fill: %d/%d\033[0m\n", strlen(buff), sizeof(buff));
	//for ( uint8_t i = 0; i < strlen(buff); i++ ) {
	//	printf("\033[33m%c", buff[i]);
	//}
	//printf("\033[0m\n");

	//int x = 430;
	//printf("x = %d\n", x);
	//printf("x = %p\n", x);

	//char xy[50];
	//sprintf(xy, "%x", x);
	//int y = (int)strtol(xy, NULL, 16);

	//printf("y = %d\n", y);
	//printf("y = %p\n", y);
//	char *prog_name;
//	char *recipient_prog_name;
//	uint8_t *hex_table;
//	for ( uint8_t i = 0; i < strlen(buff); i++ ) {
//		if ( buff[i] == '{' ) {
//			i++;
//			if ( buff[i] == '7' ) {
//				prog_name_len = 7;
//			}
//			prog_name = malloc( sizeof(char) * prog_name_len);
//			i++;
//			for ( uint8_t j = 0; j < prog_name_len; j++ ) {
//				prog_name[j] = buff[i+=1];
//			}
//			fprintf(stderr, "prog_name_len: %d\n", prog_name_len);
//			fprintf(stderr, "prog_name: %s\n", prog_name);
//			free(prog_name);
//			prog_name = NULL;
//			i++;
//			i++;
//		}
//	}
	return 0;
}
