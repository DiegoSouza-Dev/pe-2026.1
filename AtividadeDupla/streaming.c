#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MAX_TEMA 20
#define TAM_MAX_TITULO 50
#define TAM_MAX_DESCRICAO 100
#define QTD_MAX_VIDEOS 50
#define TAM_MAX_NOME 20
#define TAM_MAX_EMAIL 40
#define MAX_USUARIOS 100
#define MAX_VIDEOS_CADASTRADOS 100

// ============= ESTRUTURAS =============
struct Video {
    int id;
    char titulo[TAM_MAX_TITULO];
    char tema[TAM_MAX_TEMA];
    char descricao[TAM_MAX_DESCRICAO];
};

struct Usuario {
    int id;
    char nome[TAM_MAX_NOME];
    char email[TAM_MAX_EMAIL];
    int idsVideosFavoritos[QTD_MAX_VIDEOS];
    int qtdVideosFavoritos;
};

// ============= VARIÁVEIS GLOBAIS =============
char nomeArqVideos[] = "videosCadastrados.bin";
char nomeArqUsuarios[] = "usuariosCadastrados.bin";

// ============= PROTÓTIPOS DE FUNÇÕES =============
// Funções de Vídeo
void cadastrarVideo();
void listarTodosVideos();
void buscarVideoPorId(int id, struct Video *v);
void atualizarVideo();
void deletarVideo();

// Funções de Usuário
void cadastrarUsuario();
void listarTodosUsuarios();
int buscarUsuarioPorEmail(char email[]);
int buscarUsuarioPorId(int id, struct Usuario *u);
void atualizarUsuario();
void deletarUsuario();
void adicionarVideoFavorito();

// Funções de Relatório
void relatorioUsuariosComFavoritos();

// Funções auxiliares
int obterProximoIdVideo();
int obterProximoIdUsuario();
void limparBuffer();

//implementaçoes 

// limpa o buffer da entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// obtem o prox ID disponivel para video
int obterProximoIdVideo() {
    FILE *arq = fopen(nomeArqVideos, "rb");
    int maxId = 0;
    struct Video v;

    if (arq != NULL) {
        while (fread(&v, sizeof(struct Video), 1, arq) == 1) {
            if (v.id > maxId) {
                maxId = v.id;
            }
        }
        fclose(arq);
    }
    return maxId + 1;
}

// obtem o prox ID disponivel para o usuario 
int obterProximoIdUsuario() {
    FILE *arq = fopen(nomeArqUsuarios, "rb");
    int maxId = 0;
    struct Usuario u;

    if (arq != NULL) {
        while (fread(&u, sizeof(struct Usuario), 1, arq) == 1) {
            if (u.id > maxId) {
                maxId = u.id;
            }
        }
        fclose(arq);
    }
    return maxId + 1;
}

// funçoes de video

void cadastrarVideo() {
    struct Video novo;
    FILE *arq = fopen(nomeArqVideos, "a+b");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo de vídeos!\n");
        return;
    }

    novo.id = obterProximoIdVideo();

    printf("\n--- CADASTRO DE NOVO VÍDEO ---\n");
    printf("Titulo: ");
    limparBuffer();
    fgets(novo.titulo, (int)sizeof(novo.titulo), stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = 0;

    printf("Tema: ");
    fgets(novo.tema, (int)sizeof(novo.tema), stdin);
    novo.tema[strcspn(novo.tema, "\n")] = 0;

    printf("Descricao: ");
    fgets(novo.descricao, (int)sizeof(novo.descricao), stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = 0;

    if (fwrite(&novo, sizeof(struct Video), 1, arq) == 1) {
        printf("\nVideo cadastrado com sucesso! ID: %d\n", novo.id);
    } else {
        printf("\nErro ao cadastrar video!\n");
    }

    fclose(arq);
}

void listarTodosVideos() {
    FILE *arq = fopen(nomeArqVideos, "rb");
    struct Video v;
    int contador = 0;

    if (arq == NULL) {
        printf("\nNenhum video cadastrado ainda!\n");
        return;
    }

    printf("\n--- LISTA DE TODOS OS VIDEOS ---\n");
    printf("-------------------------------------------------\n");

    while (fread(&v, sizeof(struct Video), 1, arq) == 1) {
        printf("ID: %d\n", v.id);
        printf("Titulo: %s\n", v.titulo);
        printf("Tema: %s\n", v.tema);
        printf("Descricao: %s\n", v.descricao);
        printf("-------------------------------------------------------------\n");
        contador++;
    }

    if (contador == 0) {
        printf("Nenhum video cadastrado.\n");
    } else {
        printf("Total de videos: %d\n", contador);
    }

    fclose(arq);
}

void buscarVideoPorId(int id, struct Video *v) {
    FILE *arq = fopen(nomeArqVideos, "rb");
    struct Video temp;

    if (arq == NULL) {
        v->id = -1;
        return;
    }

    while (fread(&temp, sizeof(struct Video), 1, arq) == 1) {
        if (temp.id == id) {
            *v = temp;
            fclose(arq);
            return;
        }
    }

    v->id = -1;
    fclose(arq);
}

void atualizarVideo() {
    int id;
    struct Video v;

    printf("\n--- ATUALIZAR VIDEO ---\n");
    printf("Digite o ID do video: ");
    scanf("%d", &id);

    buscarVideoPorId(id, &v);

    if (v.id == -1) {
        printf("Video nso encontrado!\n");
        return;
    }

    printf("\nVideo encontrado: %s\n", v.titulo);
    printf("Novo titulo (ou pressione Enter para manter): ");
    limparBuffer();

    char temp[TAM_MAX_TITULO];
    if (fgets(temp, (int)sizeof(temp), stdin) != NULL && temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(v.titulo, temp);
    }

    printf("Novo tema (ou pressione Enter para manter): ");
    if (fgets(temp, (int)sizeof(temp), stdin) != NULL && temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(v.tema, temp);
    }

    printf("Nova descricao (ou pressione Enter para manter): ");
    char tempDesc[TAM_MAX_DESCRICAO];
    if (fgets(tempDesc, (int)sizeof(tempDesc), stdin) != NULL && tempDesc[0] != '\n') {
        tempDesc[strcspn(tempDesc, "\n")] = 0;
        strcpy(v.descricao, tempDesc);
    }

    // reescrever ou editar o arquivo
    FILE *arq = fopen(nomeArqVideos, "r+b");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    struct Video v_temp;
    while (fread(&v_temp, sizeof(struct Video), 1, arq) == 1) {
        if (v_temp.id == id) {
            fseek(arq, -(long)sizeof(struct Video), SEEK_CUR);
            fwrite(&v, sizeof(struct Video), 1, arq);
            printf("Video atualizado com sucesso!\n");
            fclose(arq);
            return;
        }
    }

    fclose(arq);
}

void deletarVideo() {
    int id;
    printf("\n--- DELETAR VIDEO ---\n");
    printf("Digite o ID do video a deletar: ");
    scanf("%d", &id);

    FILE *arqOriginal = fopen(nomeArqVideos, "rb");
    FILE *arqTemp = fopen("temp_videos.bin", "wb");

    if (arqOriginal == NULL || arqTemp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    struct Video v;
    int encontrado = 0;

    while (fread(&v, sizeof(struct Video), 1, arqOriginal) == 1) {
        if (v.id != id) {
            fwrite(&v, sizeof(struct Video), 1, arqTemp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arqOriginal);
    fclose(arqTemp);

    if (encontrado) {
        remove(nomeArqVideos);
        rename("temp_videos.bin", nomeArqVideos);
        printf("Video deletado com sucesso!\n");
    } else {
        remove("temp_videos.bin");
        printf("Video não encontrado!\n");
    }
}

// funçoes do usuario -----------

void cadastrarUsuario() {
    struct Usuario novo;
    FILE *arq = fopen(nomeArqUsuarios, "a+b");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo de usuarios!\n");
        return;
    }

    printf("\n--- CADASTRO DE NOVO USUARIO ---\n");
    printf("Email: ");
    limparBuffer();
    fgets(novo.email, (int)sizeof(novo.email), stdin);
    novo.email[strcspn(novo.email, "\n")] = 0;

    // Verifica se email já existe
    if (buscarUsuarioPorEmail(novo.email) != -1) {
        printf("Email ja cadastrado!\n");
        fclose(arq);
        return;
    }

    printf("Nome: ");
    fgets(novo.nome, (int)sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    novo.id = obterProximoIdUsuario();
    novo.qtdVideosFavoritos = 0;
    for (int i = 0; i < QTD_MAX_VIDEOS; i++) {
        novo.idsVideosFavoritos[i] = -1;
    }

    if (fwrite(&novo, sizeof(struct Usuario), 1, arq) == 1) {
        printf("\n Usuario cadastrado com sucesso! ID: %d\n", novo.id);
    } else {
        printf("\n Erro ao cadastrar usuario!\n");
    }

    fclose(arq);
}

void listarTodosUsuarios() {
    FILE *arq = fopen(nomeArqUsuarios, "rb");
    struct Usuario u;
    int contador = 0;

    if (arq == NULL) {
        printf("\n Nenhum usuario cadastrado ainda!\n");
        return;
    }

    printf("\n--- LISTA DE TODOS OS USUARIOS ---\n");
    printf("---------------------------------------------------\n");

    while (fread(&u, sizeof(struct Usuario), 1, arq) == 1) {
        printf("ID: %d\n", u.id);
        printf("Nome: %s\n", u.nome);
        printf("Email: %s\n", u.email);
        printf("Quantidade de videos favoritos: %d\n", u.qtdVideosFavoritos);
        printf("---------------------------------------------\n");
        contador++;
    }

    if (contador == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        printf("Total de usuarios: %d\n", contador);
    }

    fclose(arq);
}

int buscarUsuarioPorEmail(char email[]) {
    FILE *arq = fopen(nomeArqUsuarios, "rb");
    int i = 0;

    if (arq == NULL) {
        return -1;
    }

    struct Usuario u;
    while (fread(&u, sizeof(struct Usuario), 1, arq) == 1) {
        if (strcmp(u.email, email) == 0) {
            fclose(arq);
            return i;
        }
        i++;
    }

    fclose(arq);
    return - 1;
}

int buscarUsuarioPorId(int id, struct Usuario *u) {
    FILE *arq = fopen(nomeArqUsuarios, "rb");
    struct Usuario temp;

    if (arq == NULL) {
        return - 1;
    }

    while (fread(&temp, sizeof(struct Usuario), 1, arq) == 1) {
        if (temp.id == id) {
            *u = temp;
            fclose(arq);
            return 0;
        }
    }

    fclose(arq);
    return -1;
}

void adicionarVideoFavorito() {
    char email[TAM_MAX_EMAIL];
    int idVideo;
    struct Usuario u;

    printf("\n--- ADICIONAR VIDEO AOS FAVORITOS ---\n");
    printf("Email do usuario: ");
    limparBuffer();
    fgets(email, (int)sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;

    if (buscarUsuarioPorId(buscarUsuarioPorEmail(email), &u) != 0) {
        printf("Usuário nao encontrado!\n");
        return;
    }

    printf("ID do video a adicionar: ");
    scanf("%d", &idVideo);

    struct Video v;
    buscarVideoPorId(idVideo, &v);

    if (v.id == -1) {
        printf("Video nao encontrado!\n");
        return;
    }

    // verificar se video ja esta nos favoritos
    for (int i = 0; i < u.qtdVideosFavoritos; i++) {
        if (u.idsVideosFavoritos[i] == idVideo) {
            printf("Este video ja esta nos favoritos!\n");
            return;
        }
    }

    if (u.qtdVideosFavoritos >= QTD_MAX_VIDEOS) {
        printf("Limite de videos favoritos atingido!\n");
        return;
    }

    u.idsVideosFavoritos[u.qtdVideosFavoritos] = idVideo;
    u.qtdVideosFavoritos++;

    // atualizar usuario no arquivo
    FILE *arq = fopen(nomeArqUsuarios, "r+b");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    struct Usuario u_temp;
    while (fread(&u_temp, sizeof(struct Usuario), 1, arq) == 1) {
        if (u_temp.id == u.id) {
            fseek(arq, -(long)sizeof(struct Usuario), SEEK_CUR);
            fwrite(&u, sizeof(struct Usuario), 1, arq);
            printf("Video adicionado aos favoritos!\n");
            fclose(arq);
            return;
        }
    }

    fclose(arq);
}

void atualizarUsuario() {
    char email[TAM_MAX_EMAIL];
    struct Usuario u;

    printf("\n--- ATUALIZAR USUARIO ---\n");
    printf("Email do usuario: ");
    limparBuffer();
    fgets(email, (int)sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;

    int posicao = buscarUsuarioPorEmail(email);
    if (posicao == -1) {
        printf("✗ Usuario nao encontrado!\n");
        return;
    }

    buscarUsuarioPorId(posicao + 1, &u); // aproximação para encontrar o usuário

    // lendo arquivo pra encontrar o usuario correto
    FILE *arq = fopen(nomeArqUsuarios, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    struct Usuario u_temp;
    int encontrado = 0;
    while (fread(&u_temp, sizeof(struct Usuario), 1, arq) == 1) {
        if (strcmp(u_temp.email, email) == 0) {
            u = u_temp;
            encontrado = 1;
            break;
        }
    }
    fclose(arq);

    if (!encontrado) {
        printf("Usuario nao encontrado!\n");
        return;
    }

    printf("\nUsuario encontrado: %s\n", u.nome);
    printf("Novo nome (ou pressione Enter para manter): ");

    char temp[TAM_MAX_NOME];
    if (fgets(temp, (int)sizeof(temp), stdin) != NULL && temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(u.nome, temp);
    }

    // att arquivo
    arq = fopen(nomeArqUsuarios, "r+b");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    while (fread(&u_temp, sizeof(struct Usuario), 1, arq) == 1) {
        if (strcmp(u_temp.email, email) == 0) {
            fseek(arq, -(long)sizeof(struct Usuario), SEEK_CUR);
            fwrite(&u, sizeof(struct Usuario), 1, arq);
            printf("✓ Usuario atualizado com sucesso!\n");
            fclose(arq);
            return;
        }
    }

    fclose(arq);
}

void deletarUsuario() {
    char email[TAM_MAX_EMAIL];

    printf("\n--- DELETAR USUARIO ---\n");
    printf("Email do usuario a deletar: ");
    limparBuffer();
    fgets(email, (int)sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;

    FILE *arqOriginal = fopen(nomeArqUsuarios, "rb");
    FILE *arqTemp = fopen("temp_usuarios.bin", "wb");

    if (arqOriginal == NULL || arqTemp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    struct Usuario u;
    int encontrado = 0;

    while (fread(&u, sizeof(struct Usuario), 1, arqOriginal) == 1) {
        if (strcmp(u.email, email) != 0) {
            fwrite(&u, sizeof(struct Usuario), 1, arqTemp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arqOriginal);
    fclose(arqTemp);

    if (encontrado) {
        remove(nomeArqUsuarios);
        rename("temp_usuarios.bin", nomeArqUsuarios);
        printf("Usuario deletado com sucesso!\n");
    } else {
        remove("temp_usuarios.bin");
        printf("Usuario não encontrado!\n");
    }
}

// funçoes 

void relatorioUsuariosComFavoritos() {
    FILE *arqUsuarios = fopen(nomeArqUsuarios, "rb");

    if (arqUsuarios == NULL) {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("||          RELATORIO: USUARIOS E SEUS VIDEOS FAVORITOS           ||\n");
    printf("-------------------------------------------------------------------\n");

    struct Usuario u;
    int totalUsuarios = 0;

    while (fread(&u, sizeof(struct Usuario), 1, arqUsuarios) == 1) {
        printf("\n----------------------------------------------------------------\n");
        printf("| USUARIO: %s\n", u.nome);
        printf("| Email: %s\n", u.email);
        printf("| ID: %d\n", u.id);
        printf("|----------------------------------------------------------------------|\n");

        if (u.qtdVideosFavoritos == 0) {
            printf("│ Nenhum video nos favoritos\n");
        } else {
            printf("│ Videos Favoritos:\n");
            for (int i = 0; i < u.qtdVideosFavoritos; i++) {
                struct Video v;
                buscarVideoPorId(u.idsVideosFavoritos[i], &v);
                printf("│   %d. %s\n", i + 1, v.titulo);
                printf("│      Tema: %s\n", v.tema);
                printf("│      Descrição: %s\n", v.descricao);
            }
        }
        printf("---------------------------------------------------------\n");
        totalUsuarios++;
    }

    printf("\nTotal de usuarios: %d\n", totalUsuarios);
    fclose(arqUsuarios);
}

// ============= FUNÇÃO PRINCIPAL =============

int main() {
    int opcao;

    while (1) {
        printf("\n");
        printf("------------------------------------------------------------------\n");
        printf("|                  STREAMING DE VIDEOS - MENU PRINCIPAL           |\n");
        printf("-------------------------------------------------------------------\n");
        printf("\n[1] Cadastrar novo usuario");
        printf("\n[2] Cadastrar novo video");
        printf("\n[3] Listar todos os videos");
        printf("\n[4] Listar todos os usuarios");
        printf("\n[5] Adicionar video aos favoritos");
        printf("\n[6] Atualizar usuario");
        printf("\n[7] Atualizar video");
        printf("\n[8] Deletar usuario");
        printf("\n[9] Deletar video");
        printf("\n[10] Relatorio: Usuarios com Favoritos");
        printf("\n[0] Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                cadastrarVideo();
                break;
            case 3:
                listarTodosVideos();
                break;
            case 4:
                listarTodosUsuarios();
                break;
            case 5:
                adicionarVideoFavorito();
                break;
            case 6:
                atualizarUsuario();
                break;
            case 7:
                atualizarVideo();
                break;
            case 8:
                deletarUsuario();
                break;
            case 9:
                deletarVideo();
                break;
            case 10:
                relatorioUsuariosComFavoritos();
                break;
            case 0:
                printf("\nObrigado por usar o sistema!\n");
                return 0;
            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}
