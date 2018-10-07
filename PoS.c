#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */


void imprimeOpcoesServico(int *opcaoServico){

    int opcao = 0;

    printf("Digite a opcao desejada: \n");
    printf("1 - Debito \n");
    printf("2 - Credito A vista \n");
    printf("3 - Credito 2x \n");
    printf("4 - Credito 3x \n");
    printf("5 - Credito 4x \n");

    scanf("%d", &opcao);

    *opcaoServico = opcao;
}

void imprimeOpcoesIniciais(int *opcaoInicial){

    int opcao = 0;

    printf("Digite a opcao desejada: \n");
    printf("1 - Venda \n");
    printf("2 - Taxas ao Portador \n");

    scanf("%d", &opcao);

    *opcaoInicial = opcao;
}

int main (){

    int opcaoInicial = 0;
    int opcaoServico = 0;
    int valor;

    imprimeOpcoesIniciais(&opcaoInicial);

    switch(opcaoInicial){
        case(1):
            printf("Venda \n\n");
            printf("----------------------------\n");
            printf("Digite o valor da venda: ");
            scanf("%d", &valor);
            printf("----------------------------\n");
            imprimeOpcoesServico(&opcaoServico);

        break;
        case(2):
            printf("Taxas ao Portador \n");
            printf("----------------------------\n");
            printf("Digite o valor para a simulacao:  ");
            scanf("%d", &valor);
            printf("----------------------------\n");
            imprimeOpcoesServico(&opcaoServico);

        break;
    }

    printf("Opção escolhida: %d \n", opcaoServico);


    return 0;
}

/**
Exibir as opcoes
	- Taxas ao Portador
		- Valor
			- Opções:
				- A vista
				- Credito A vista
				- Parcelado 1
				- Parcelado 2
					- Processar o que for nececssario
	- MEnsagem de sucesso || Mensagem de erro
	- Compra
		- Valor
			- Opções:
				- A vista
				- Credito A vista
				- Parcelado 1
				- Parcelado 2
					- Processar o que for nececssario
	- MEnsagem de sucesso || Mensagem de erro
**/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <curl/curl.h>


typedef struct string_buffer_s
{
    char * ptr;
    size_t len;
} string_buffer_t;


static void string_buffer_initialize( string_buffer_t * sb )
{
    sb->len = 0;
    sb->ptr = malloc(sb->len+1);
    sb->ptr[0] = '\0';
}


static void string_buffer_finish( string_buffer_t * sb )
{
    free(sb->ptr);
    sb->len = 0;
    sb->ptr = NULL;
}


static size_t string_buffer_callback( void * buf, size_t size, size_t nmemb, void * data )
{
    string_buffer_t * sb = data;
    size_t new_len = sb->len + size * nmemb;

    sb->ptr = realloc( sb->ptr, new_len + 1 );

    memcpy( sb->ptr + sb->len, buf, size * nmemb );

    sb->ptr[ new_len ] = '\0';
    sb->len = new_len;

    return size * nmemb;

}


/**static size_t header_callback(char * buf, size_t size, size_t nmemb, void * data )
{
    return string_buffer_callback( buf, size, nmemb, data );
}


static size_t write_callback( void * buf, size_t size, size_t nmemb, void * data )
{
    return string_buffer_callback( buf, size, nmemb, data );
}**/

/**
int request(char *myurl){

    int argc, char * argv[];

    CURL * curl;
    CURLcode res;
    string_buffer_t strbuf;

    char * myurl = argv[1];

    string_buffer_initialize( &strbuf );

    curl = curl_easy_init();

    if(!curl)
    {
        fprintf(stderr, "Fatal: curl_easy_init() error.\n");
        string_buffer_finish( &strbuf );
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, myurl );
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L );
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback );
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback );
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf );
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &strbuf );

    res = curl_easy_perform(curl);

    if( res != CURLE_OK )
    {
        fprintf( stderr, "Request failed: curl_easy_perform(): %s\n", curl_easy_strerror(res) );

        curl_easy_cleanup( curl );
        string_buffer_finish( &strbuf );

        return EXIT_FAILURE;
    }

    printf( "%s\n\n", strbuf.ptr );

    curl_easy_cleanup( curl );
    string_buffer_finish( &strbuf );

    return EXIT_SUCCESS;
}
**/

