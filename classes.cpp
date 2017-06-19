#include <string>

class Usuario; //TODO: criar subclasses
class Autenticador; //antigo guardinha, responsável por permitir novos cadastros e agendamento
class Gerenciador; //antiga porta, responsável por permitir entrada a lab e salas
//class BD; //onde ficam todos os dados de usuarios
//class Laboratorio; //conjunto de salas
//class Sala; //self explanatory
//class Dia; //uma classe com struct de todos os eventos do dia



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
	/**
	* Informação inútil por enquanto
	*/
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
			std::cout<<"Senha errada, tente novamente."<<std::endl;
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
/**
* @brief Gerenciador de acesso ao Laboratório.
*
* Ele será o responsável por receber as informações do usuário para liberar entrada ao laboratório.
*/
class Gerenciador{
public:
	Gerenciador(){}

	int permitirAcesso(int escolhido, bool autenticado) {
	    if (!autenticado){
	        std::cout<<"Você não tem acesso ao laboratório."<<std::endl;
	        return -1;
	    }
	    else {
	        if (escolhido == 0) {
	            std::cout<<"Portas liberadas, você tem acesso ao laboratório, agende sua sala."<<std::endl;
	            return 0;
	        }
	        if (escolhido == 1) {
	            std::cout<<"Portas liberadas, você tem acesso à sala 1, boa aula."<<std::endl;
	            return 1;
	        }
	        if (escolhido == 2) {
	            std::cout<<"Portas liberadas, você tem acesso à sala 2, boa aula."<<std::endl;
	            return 2;
	        }
	        if (escolhido == 3) {
	            std::cout<<"Portas liberadas, você tem acesso à sala 3, boa aula."<<std::endl;
	            return 3;
	        }
	        else {
	            std::cout<<"Escolha inadequada, tente novamente."<<std::endl;
	        }
	    }
	    return -1;
	}
};

/**
* @brief Classe principal, comunica com gerenciador e autenticador
*
* Tipos de usuários
* -1: não cadastrado
* 0: genérico
* 1: professor (pode reservar qualquer evento, pode entrar somente nas salas designadas)
* 2: aluno (não pode reservar, pode entrar somente nas salas designadas)
* 3: palestrante (pode reservar somente eventos únicos, pode entrar somente nas salas designadas)
* 4: funcionario (pode reservar qualquer evento, pode entrar em tudo)
*/
class Usuario{
private:
	std::string nome;
	std::string sobrenome;
	std::string cpfOuMatricula;
	int id;
	int tipo;
	int acesso; /* verificar se vai pro diagrama*/
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
	std::string getCPFouMatricula(void){
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
	int requisitarAcesso(Gerenciador& gerenciador, int sala){
		if (id > 0){
			return gerenciador.permitirAcesso(sala, true);
		}
		return -1;
	}
    //pedirReserva(Sala sala, int horario, int grauDeAcesso, Autenticador autenticador);
    //pedirEntrada(int salaEscolhida);
    //pedirAcessoMaior();
};

class Dia{
private:
	std::string nome;
	std::string eventos[12];
	//Horários disponíveis para eventos =	{0,2,4,6,8,10,12,14,16,18,20,22}

public:
	Dia(){
		nome = "Segunda";
	}
	Dia(std::string nomeDoDia){
		nome = nomeDoDia;
	}
	std::string mudaEvento(Autenticador& autenticador, std::string token, std::string novoEvento, int horario){
		if (autenticador.getToken() == token){
			eventos[horario] = novoEvento;
			return "Evento alterado com sucesso.";
		}
		else{
			return "Algo de errado aconteceu";
		}
	}
	std::string mostraEvento(int horario){
		return eventos[horario];
	}
	std::string mostraNomeDia(){
		return nome;
	}
};

class Semana{
private:
	Dia dias[7];

public:
	Semana(){
		dias[0] = Dia("Segunda");
		dias[1] = Dia("Terça");
		dias[2] = Dia("Quarta");
		dias[3] = Dia("Quinta");
		dias[4] = Dia("Sexta");
		dias[5] = Dia("Sábado");
		dias[6] = Dia("Domingo");
	}

	std::string visualizaEventos(void){
		for(int day = 0; day < 7; day++){
			std::cout<<dias[day].mostraNomeDia()<<std::endl;
			for (int hour = 0; hour < 12; hour++) {
				std::cout<<hour<<"h até "<<hour+2 <<"h: "<<dias[day].mostraEvento(hour)<<std::endl;
			}
			std::cout<<std::endl;
		}
		return "OK";
	}
};

/*class Laboratorio{
private:
	Autenticador autenticador = Autenticador("Padrão", 10);
	Gerenciador gerenciador = Gerenciador();
	//Sala salas[];

public:


};*/

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

*/
