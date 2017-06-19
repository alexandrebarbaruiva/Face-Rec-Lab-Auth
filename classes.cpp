#include <string>

/*
class Usuario; //TODO: criar subclasses
class Autenticador; //antigo guardinha, responsável por permitir novos cadastros e agendamento
class Gerenciador; //antiga porta, responsável por permitir entrada a lab e salas
class BD; //onde ficam todos os dados de usuarios
class Laboratorio; //conjunto de salas
class Sala; //self explanatory
class Dia; //uma classe com struct de todos os eventos do dia
*/
/*

Tipos de usuários
-1: não cadastrado
0: genérico
1: professor (pode reservar qualquer evento, pode entrar somente nas salas designadas)
2: aluno (não pode reservar, pode entrar somente nas salas designadas)
3: palestrante (pode reservar somente eventos únicos, pode entrar somente nas salas designadas)
4: funcionario (pode reservar qualquer evento, pode entrar em tudo)

*/
class Usuario;
class Autenticador;

/** @brief Classe responsável por autenticar reservas de salas e possíveis erros
* com a identificação facial.
*
* Além disso, somente é possível registrar novos usuários com a presença
* de um autenticador. O mesmo vale para modificação de informações de usuários.
* Sem um autenticador, somente é possível entrar e sair dos laboratórios.
*
* É possível que um usuário seja um autenticador, contudo haverá dois registros diferentes
* para a mesma pessoa no sistema.
*/
class Autenticador{
private:
	std::string nome;
	std::string senha; //para pedir outro token e acessar outras infos
	std::string token; //para fazer reserva
	int id;

public:
	/**
	* Construtor de autenticador vazio, não válido.
	*/
	Autenticador(){
		nome = "";
		senha = "";
		id = -1;
		token = "0";
	}

	/**
	* Construtor de autenticador válido, o token é gerado automaticamente e a senha
	* é padrão para todos, a mudança de senha deve ocorrer no ato do registro de um
	* novo autenticador.
	*/
	Autenticador(std::string novoNome, int novoId){
		nome = novoNome;
		senha = "padrao5000";
		id = novoId;
		token = geradorToken();
	}
	std::string getNome(void){
		return nome;
	}
	int getId(void){
		return id;
	}
	void mudaSenha(std::string novaSenha, std::string antigaSenha){
		if (senha == antigaSenha and id != -1){
			senha = novaSenha;
			std::cout<<"Senha mudada com sucesso."<<std::endl;
		}
		else if (id == -1) {
			std::cout<<"Usuário não registrado adequadamente."<<std::endl;
		}
		else{
			std::cout<<"Senha errada, você tem mais 3 tentativas."<<std::endl;
		}
	}
	std::string geradorToken(void){
		std::string token;
		static const char letras[] =
					"0123456789"
					"!@#$%^&*"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
					"abcdefghijklmnopqrstuvwxyz";
		int tamanho = sizeof(letras) - 1;

		for (int i = 0; i < 13; i++){
			token += letras[rand() % tamanho];
		}
		std::cout<<token<<std::endl;
		return token;
	}
	std::string getToken(void){
		return token;
	}
};

class Usuario{
private:
	std::string nome;
	std::string sobrenome;
	std::string cpfOuMatricula;
	int id;
//TODO: fotos[]


public:
    Usuario(){
		nome = "";
	    sobrenome = "";
		cpfOuMatricula = "";
	    id = -1;
	}
	Usuario(std::string novoNome, std::string novoSobrenome, std::string novoCPFouMatricula, int novoId){
		nome = novoNome;
	    sobrenome = novoSobrenome;
		cpfOuMatricula = novoCPFouMatricula;
		id = novoId;
	}

	std::string getNome(void){
		return nome;
	}
	std::string getSobrenome(void){
		return sobrenome;
	}
	std::string getCPFouMatricula(){
		return cpfOuMatricula;
	}
	int getId(void){
		return id;
	}
	std::string pedirReserva(Autenticador& autenticador, std::string token){
		if (autenticador.getToken() == token){
			return "Reserva feita com sucesso.";
		}
		else{
			return "Algo de errado aconteceu";
		}
	}
	std::string requisitarAcesso(){
		return "Acesso permitido.";
	}
    //pedirReserva(Sala sala, int horario, int grauDeAcesso, Autenticador autenticador);
    //pedirEntrada(int salaEscolhida);
    //pedirAcessoMaior();
};









/*
Usuario::pedirReserva(void){
    nome = "Not a person";
    cpf = "Not a number";
}
Usuario::pedirEntrada(int salaEscolhida){
    if (this.acesso > 100 ) {
        processo(salaEscolhida, true);
    } else if (this.acesso > 10) {
        if(salaEscolhida == 1 and (this.acesso == 12 or this.acesso == 13)){
            processo(salaEscolhida, true);
        }
        else if(salaEscolhida == 2 and (this.acesso == 12 or this.acesso == 23)){
            processo(salaEscolhida, true);
        }
        else if(salaEscolhida == 3 and (this.acesso == 13 or this.acesso == 23)){
            processo(salaEscolhida, true);
        }
        else{
            processo(salaEscolhida, true);
        }
    } else {
        if(acesso == salaEscolhida){
            processo(salaEscolhida, true);
        }
        else{
            processo(salaEscolhida, false);
        }
    }

}
*/
/*
class reserva{
	user
	sala
	horario
	duracao
	proposito
	users[]
}

class aula{
	disciplina
	dias[]
	horario
	duracao
	alunos
	professor
	id
	turma
	sala
}


class laboratorio{
	users_cadastrados[]
	user
	porta
	guarda
	reservas

	adicionarUser()
	removerUser()

	autenticar(user)
		portao.abrir ou portao.fechar
	{
		se user.tipo == aluno, verifica nas aulas

	}
}

class guardinha{

	permitirAcesso(user)

}

class porta{
	func abrir -> "acesso permitido" (abre porta)
	func erro -> "acesso negado"
}
*/
