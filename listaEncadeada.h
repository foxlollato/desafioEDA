
struct elemento{
    int valor;
};

typedef struct nodo Lista; //defino tipo
							 //Lista == ponteiro para
							 //estrutura com dois campos

Lista* criaLista();
void apagaLista(Lista* inicio);
int insereFinal(Lista* inicio, struct elemento aluno);
int insereInicio(Lista* inicio, struct elemento aluno);
int insereOrdenada(Lista* inicio, struct elemento aluno);
int removeMatricula(Lista* inicio, int mat);
int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);
int tamLista(Lista* inicio);
int listaVazia(Lista* inicio);
int listaCheia(Lista* inicio);
void imprimeLista(Lista* inicio);
int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno);
int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno);
int subLista(Lista*, Lista *, int, int);
