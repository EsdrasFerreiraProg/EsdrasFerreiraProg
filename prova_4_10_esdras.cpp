#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct funcionario{ //questao 1 e 3
  string nome;
  int matricula;
  double salario;
  string funcao;
  funcionario *prox;
};

struct noArvore{
  funcionario *f;
  noArvore *esq, *dir;
};


noArvore* inicializar(){
  return NULL;
}

void soma_pre(noArvore* raiz, double& soma){ //questao 1 e 3
    if(raiz!=NULL){
        soma += raiz->f->salario;
        soma_pre(raiz->esq, soma);
        soma_pre(raiz->dir, soma);
  }

}

void imprimir_pre(noArvore* raiz){
  if(raiz!=NULL){
    cout<<"\nNome do funcionario: " << raiz->f->nome << "\nMatricula do funcionario: " << raiz->f->matricula <<"\n";
    imprimir_pre(raiz->esq);
    imprimir_pre(raiz->dir);
  }
}

void imprimir_central(noArvore* raiz){
  if(raiz!=NULL){
    imprimir_central(raiz->esq);
    cout<<"\nNome do funcionario: " << raiz->f->nome << "\nMatricula do funcionario: " << raiz->f->matricula <<"\n";

    imprimir_central(raiz->dir);
  }
}

void imprimir_pos(noArvore* raiz){
  if(raiz!=NULL){
    imprimir_pos(raiz->esq);
    imprimir_pos(raiz->dir);
    cout<<"\nNome do funcionario: " << raiz->f->nome << "\nMatricula do funcionario: " << raiz->f->matricula <<"\n";
  }
}

void inserir_bst(noArvore*& raiz, int info, funcionario* func){
  if(raiz == NULL){
    raiz = new noArvore;
    raiz->f = func;
    raiz->esq = NULL;
    raiz->dir = NULL;

  }
  else if(info < raiz->f->matricula)
    inserir_bst(raiz->esq, info,func);
  else if(info > raiz->f->matricula)
    inserir_bst(raiz->dir,info,func);
  else{
    cout<<"Elemento já existe na árvore."<<endl;
  }
}

void inserir_bst_nome(noArvore*& raiz, string info, funcionario* func){
  if(raiz == NULL){
    raiz = new noArvore;
    raiz->f = func;
    raiz->esq = NULL;
    raiz->dir = NULL;
  }
  else if(info < raiz->f->nome)
    inserir_bst_nome(raiz->esq, info,func);
  else if(info > raiz->f->nome)
    inserir_bst_nome(raiz->dir,info,func);
  else{
    cout<<"Elemento já existe na árvore."<<endl;
  }
}

noArvore* buscar_elemento(noArvore* raiz,int info){
  if(raiz == NULL || raiz->f->matricula == info)
    return raiz;
  else if(info < raiz->f->matricula)
    return buscar_elemento(raiz->esq,info);
  else
    return buscar_elemento(raiz->dir,info);
}

noArvore* buscar_elemento_nome(noArvore* raiz, string info){
  if(raiz == NULL || raiz->f->nome == info)
    return raiz;
  else if(info < raiz->f->nome)
    return buscar_elemento_nome(raiz->esq,info);
  else
    return buscar_elemento_nome(raiz->dir,info);
}

int tamanho(noArvore* raiz){
  if(raiz == NULL)
    return 0;
  else
    return tamanho(raiz->esq) + tamanho(raiz->dir) + 1;
}

int somar_elementos(noArvore* raiz){
  if(raiz == NULL)
    return 0;
  else
    return somar_elementos(raiz->esq) + somar_elementos(raiz->dir) + raiz->f->matricula;
}

int altura(noArvore* raiz){
  if(raiz == NULL)
    return -1;
  else{
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);
    if(altE > altD)
      return altE + 1;
    else
      return altD + 1;
  }
}

noArvore* maior(noArvore* raiz){
  if(raiz == NULL || raiz->dir == NULL)
    return raiz;
  else
    return maior(raiz->dir);
}

bool remover(noArvore *&raiz, int elemento){
  if(raiz == NULL)
    return false;
  else if(elemento < raiz->f->matricula)
    return remover(raiz->esq,elemento);
  else if(elemento > raiz->f->matricula)
    return remover(raiz->dir,elemento);
  else{
    if(raiz->esq == NULL && raiz->dir == NULL){
      delete raiz;
      raiz = NULL;
    }
    else if(raiz->esq == NULL){
      noArvore *aux = raiz;
      raiz = raiz->dir;
      delete aux;
    }
    else if(raiz->dir == NULL){
      noArvore *aux = raiz;
      raiz = raiz->esq;
      delete aux;
    }
    else{
      noArvore *aux = maior(raiz->esq);
      raiz->f->matricula = aux->f->matricula;
      raiz->esq = aux->esq;
      delete aux;
    }
    return true;
  }
}

bool balanceada(noArvore *raiz){
  if(raiz == NULL)
    return true;
  else{
    if(abs(altura(raiz->esq) - altura(raiz->dir)) > 1)
      return false;
    else
      return balanceada(raiz->esq) && balanceada(raiz->dir) ;
  }
}

void gerar_vetor(noArvore *raiz, int* vet, int &i){
  if(raiz != NULL){
    gerar_vetor(raiz->esq,vet,i);
    vet[i] = raiz->f->matricula;
    i++;
    gerar_vetor(raiz->dir,vet,i);
  }
}

void gerar_vetor_nome(noArvore *raiz, string* vet, int &i){
  if(raiz != NULL){
    gerar_vetor_nome(raiz->esq,vet,i);
    vet[i] = raiz->f->nome;
    i++;
    gerar_vetor_nome(raiz->dir,vet,i);
  }
}

void destruir(noArvore *&raiz){
  if(raiz != NULL){
    destruir(raiz->esq);
    destruir(raiz->dir);
    delete raiz;
    raiz = NULL;
  }
}

void gerar_arvore(noArvore*& raiz, int* vet, int ini, int fim){
  if(fim < ini || raiz == NULL)
    raiz = NULL;
  else{
    int meio = (ini+fim)/2;
    raiz = new noArvore;
    raiz->f->matricula = vet[meio];
    gerar_arvore(raiz->esq, vet, ini, meio-1);
    gerar_arvore(raiz->dir, vet, meio+1, fim);
  }
}
void gerar_arvore_nome(noArvore*& raiz, string* vet, int ini, int fim){
  if(fim < ini || raiz == NULL)
    raiz = NULL;
  else{
    int meio = (ini+fim)/2;
    raiz = new noArvore;
    raiz->f->nome = vet[meio];
    gerar_arvore_nome(raiz->esq, vet, ini, meio-1);
    gerar_arvore_nome(raiz->dir, vet, meio+1, fim);
  }
}

void balanceamento_estatico(noArvore*& raiz){
  if(!balanceada(raiz)){
    int tam = tamanho(raiz);
    int* vetor = new int[tam];
    int indice = 0;
    gerar_vetor(raiz, vetor, indice);
    destruir(raiz);
    gerar_arvore(raiz, vetor, 0, tam-1);
    delete [] vetor;
  }
}

void balanceamento_estatico_nome(noArvore*& raiz){
  if(!balanceada(raiz)){
    int tam = tamanho(raiz);
    string* vetor = new string[tam];
    int indice = 0;
    gerar_vetor_nome(raiz, vetor, indice);
    destruir(raiz);
    gerar_arvore_nome(raiz, vetor, 0, tam-1);
    delete [] vetor;
  }
}

bool inserir_funcionario(funcionario*& f, string n, int m, noArvore*& arvore_matricula, noArvore*& arvore_nome){
    funcionario* funcionario_novo = new funcionario;
    funcionario_novo->matricula = m;
    funcionario_novo->nome = n;
    funcionario_novo->prox = NULL;

    if (f == NULL){ //se não houver nada, lista vazias de funcionarios
        f = funcionario_novo;
        inserir_bst(arvore_matricula, m , f);
        inserir_bst_nome(arvore_nome, n, f);

        return true;
        }

    else if (f->prox == NULL){//se for o segundo

        if (funcionario_novo->nome < f->nome){// se for menor que o que está
            funcionario_novo->prox = f;
            f = funcionario_novo;
            inserir_bst(arvore_matricula, f->matricula, f);
            inserir_bst_nome(arvore_nome, f->nome, f);

            return true;
            }
        else if (funcionario_novo->nome > f->nome) //maior do que o que está
            f->prox = funcionario_novo;
            inserir_bst_nome(arvore_nome, f->prox->nome, f->prox);
            inserir_bst(arvore_matricula, f->prox->matricula, f->prox);

            return true;
            }

    else if(funcionario_novo->nome < f->nome && f->prox != NULL){ //se for o primeiro em uma lista infinita
        funcionario_novo->prox = f;
        f = funcionario_novo;
        inserir_bst_nome(arvore_nome, f->nome, f);
        inserir_bst(arvore_matricula, f->matricula, f);

        return true;
    }
    else{

        funcionario* aux = f;
        while(aux != NULL){
            if (aux->prox == NULL && aux->nome < funcionario_novo->nome){ //fim
                aux->prox = funcionario_novo;
                inserir_bst_nome(arvore_nome, aux->prox->nome, aux->prox);
                inserir_bst(arvore_matricula, aux->prox->matricula, aux->prox);

                return true;
            }

            else if(funcionario_novo->nome > aux->nome && funcionario_novo->nome < aux->prox->nome){//observar se está no meio
                funcionario_novo->prox = aux->prox;
                aux->prox = funcionario_novo;
                inserir_bst_nome(arvore_nome, aux->prox->nome, aux->prox);
                inserir_bst(arvore_matricula, aux->prox->matricula, aux->prox);

                return true;
            }

        aux = aux->prox;

        }
    }

}

funcionario* inicializar_funcionario(){
    return NULL;
}

void imprimir_funcionarios(funcionario* f){
    funcionario* aux = f;

    while(aux != NULL){
        cout << aux->nome << "\n";
        aux = aux->prox;
    }

}

struct apontador{//questao 1 e 3
    int indice;
    funcionario* prox;

};

void insere_na_tabela_hash(funcionario*f, list<apontador*>& l){//questao 1 e 3
    int transformacao = f->matricula % 25;

    for (apontador* a: l){
        if(a->indice == transformacao && a->prox!= NULL){
            funcionario* aux = a->prox;

            while(aux != NULL){
                if (aux->prox == NULL){
                    aux->prox = f;
                    break;
                }

                aux = aux->prox;

            }

        }
        else if(a->indice == transformacao && a->prox== NULL){
            a->prox = f;

        }
    }

}

void imprimir(list<apontador*> l){//questao 1 e 3
    for(apontador*a: l){
        if(a->prox != NULL){
            funcionario* aux = a->prox;
            cout << a->indice << endl;
            while(aux != NULL){
                cout << aux->salario << endl;
                aux = aux->prox;
            }
        }
    }

}

int main() { //questao 1 e 3

    noArvore* arvore = inicializar();
    noArvore* arvore_ordenada_nome = inicializar();
    funcionario* novo_funcionario = inicializar_funcionario();


    list<apontador*> lista_de_apontadores(0);

    for(int i=0; i < 25; i++){
        apontador* a = new apontador();
        a->prox=NULL;
        a->indice = i;
        lista_de_apontadores.push_back(a);
        }

    while (true){

        funcionario* f = new funcionario();

        f->prox=NULL;
        string nome;
        int matricula;
        string funcao;
        double salario;

        cout << "DIGITE A MATRICULA DO NOVO FUNCIONARIO: ";
        cin >> matricula;
        if (matricula == 0) // para brecar
            break;

        if (matricula == 3){ //soma dos salários em uma arvore
            double soma = 0.0;
            soma_pre(arvore, soma);
            cout <<soma << endl;
            }
        cout << "DIGITE O NOME DO NOVO FUNCIONARIO: ";
        cin >> nome;
        cout << "DIGITE A FUNCAO QUE O NOVO FUNCIONARIO IRA EXERCER: ";
        cin >> funcao;
        cout << "DIGITE O SALARIO DO FUNCIONARIO: ";
        cin >> salario;

        f->matricula = matricula;
        f->nome = nome;
        f->salario = salario;
        f->funcao = funcao;


        insere_na_tabela_hash(f, lista_de_apontadores);//questao 1 e 3, funcao principal da questao 1

        inserir_bst(arvore, matricula, f);//questao 1 e 3

    }

   /* while (true){
        int escolha;
        cout << "1 - Inserir elemento no fim da lista\n" << "2 - Buscar elemento na lista por matrícula\n" <<  "3 - Buscar elemento na lista por nome \n" << "4 - Imprimir todos os elementos por ordem de matrícula \n" <<
         "5 - Imprimir todos os elementos por ordem de nome\n" <<  "6 - Balancear árvores \n" << "0 - Sair";
        cout << "\nDIGITE AQUI: ";
        cin  >> escolha;
        if (escolha == 1){
            string nome;
            int matricula;
            cout << "Digite o nome do funcionario: ";
            cin >> nome;
            cout << "Digite a matricula do funcionario: ";
            cin >> matricula;
            inserir_funcionario(novo_funcionario, nome, matricula, arvore, arvore_ordenada_nome);
            cout << "funcionário inserido!\n";
        }

        if (escolha == 2){
            int matricula;
            cout << "Digite a matricula do funcionario: ";
            cin >> matricula;
            cout << "\nNome do funcionario: " << buscar_elemento(arvore, matricula)->f->nome << "\n" << "Numero da matricula: " << buscar_elemento(arvore, matricula)->f->matricula << "\n";
        }

        if (escolha ==3){
            string nome;
            cout << "Digite o nome do funcionario: ";
            cin >> nome;
            cout << "\nNome do funcionario: " << buscar_elemento_nome(arvore_ordenada_nome, nome)->f->nome << "\n" << "Numero da matricula: " << buscar_elemento_nome(arvore_ordenada_nome, nome)->f->matricula << "\n";

        }
        if (escolha == 4){
            imprimir_central(arvore);

        }
        if (escolha == 5){
            imprimir_central(arvore_ordenada_nome);
        }
        if (escolha ==6 ){
            balanceamento_estatico(arvore);

            cout << "ÁRVORES BALANCEADAS!\n";
        }

        if (escolha == 0){
            break;
        }

    */


}
