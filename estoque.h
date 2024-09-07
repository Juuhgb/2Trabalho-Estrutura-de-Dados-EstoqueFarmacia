// Tipo que define o medicamento
typedef struct medicamento Medicamento ;
// Tipo que define a rvore
typedef struct arvore Arvore ;
/* Cria um novo medicamento */
Medicamento * CriaMedicamento ( char * nome , int codigo , float valor , int* data_de_validade ) ;
/* Cria uma arvore vazia */
Arvore * CriaArvore () ;
/* Insere um medicamento pelo codigo na arvore */ Arvore * InsereArvoreMedicamento ( Arvore * a, Medicamento * m ) ;
/* Retira um medicamento de uma determinada rvore */

Arvore * RetiraArvoreMedicamento ( Arvore * a , int id_medicamento ) ;
/* Verifica se um medicamento e s t presente em uma determinada
arvore */
int VerificaArvoreMedicamento ( Arvore * a , int id_medicamento ) ;
/* Verifica se existe um medicamento vencido em uma determinada
arvore */
int VerificaArvoreValidade ( Arvore * a , int * data ) ;
/* Imprime em ordem pelo codigo todos os medicamentos de uma arvore
(em ordem )*/
void ImprimeArvoreMedicamentos ( Arvore * a ) ;