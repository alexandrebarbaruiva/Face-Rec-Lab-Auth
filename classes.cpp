#include <string>

class Usuario; // REVIEW: subclasses viraram tipo
class Autenticador; //antigo guardinha, responsável por permitir novos cadastros e agendamento
class Gerenciador; //antiga porta, responsável por permitir entrada a lab e salas
//class BD; //onde ficam todos os dados de usuarios
class Laboratorio; //conjunto de salas
class Sala; //self explanatory
class Dia; //uma classe com struct de todos os eventos do dia
class Semana;



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
		//mudar pra ler info de JSON
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
	* Informação inútil por enquanto, quando implementar JSON vai ser maravilhoso.
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
* TODO: Concluir.
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
* 0: genérico (somente pode entrar no laboratório)
* 1: aluno (não pode reservar, pode entrar somente nas salas designadas)
* 2: palestrante (pode reservar somente eventos únicos, pode entrar somente nas salas designadas)
* 3: professor (pode reservar qualquer evento, pode entrar somente nas salas designadas)
* 4: funcionario (pode reservar qualquer evento, pode entrar em tudo)
*
* TODO: Concluir.
*/
class Usuario{
private:
	std::string nome;
	std::string sobrenome;
	std::string cpf;
	std::string matricula;
	int id;
	int tipo;
	//REVIEW: int acesso; @Caio: verificar se vai pro diagrama @Alexandre: Não vai pro diagrama, tipo e acesso são redundantes
	//TODO: fotos[] - @Alexandre: Acho que não vai

public:
    Usuario(){
		nome = "";
	    sobrenome = "";
		cpf = "";
	    id = -1;
	}
	Usuario(std::string novoNome, std::string novoSobrenome, std::string novoCPF, int novoId){
		nome = novoNome;
	    sobrenome = novoSobrenome;
		cpf = novoCPF;
		id = novoId;
	}

	std::string getNome(void){
		return nome;
	}
	std::string getSobrenome(void){
		return sobrenome;
	}
	std::string getCPF(void){
		return cpf;
	}
	int getId(void){
		return id;
	}

	/** @brief Função responsável pela reserva de salas para eventos.
	*
	* FIXME: Melhorar função
	*
	*/
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
};

class Evento{
private:
	std::string nome;
	std::string cpf[20];

public:
	Evento(){
		nome = "";
		for(int i = 0; i < 20; i++){
			cpf[i] = "";
		}
	}
	Evento(std::string novoNome){
		nome = novoNome;
		for(int i = 0; i < 20; i++){
			cpf[i] = "";
		}
	}
	void setNomeEvento(std::string novoNome){
		nome = novoNome;
	}
	std::string getNomeEvento(){
		return nome;
	}
	std::string adicionaParticipante(std::string cpfParticipante){
		//validaParticipante(cpfParticipante);
		for (int vaga = 0; vaga < 20; vaga++){
			if(cpf[vaga] == ""){
				cpf[vaga] = cpfParticipante;
				return "Participante registrado com sucesso. Há " + std::to_string(19-vaga) + " vagas disponíveis.";
			}
		}
		return "Não há vagas disponíveis.";
	}
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
	Dia(std::string nomeDia){
		nome = nomeDia;
	}
	std::string mudaEvento(Autenticador& autenticador, std::string token, std::string novoEvento, int horario){
		horario = horario/2;
		if (autenticador.getToken() == token){
			eventos[horario] = novoEvento;
			return "Evento alterado com sucesso.";
		}
		else{
			return "Algo de errado aconteceu.";
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

	std::string visualizaEventosDia(int diaDesejado){
		std::string resposta;
		resposta += (dias[diaDesejado].mostraNomeDia() + "\n");
		for (int hour = 0; hour < 12; hour++) {
			if(dias[diaDesejado].mostraEvento(hour) != ""){
				resposta += (std::to_string(2*hour) + "h até " + std::to_string((2*hour)+2) + "h: " + dias[diaDesejado].mostraEvento(hour) + "\n");
			}
		}
		std::cout<<resposta;
		return "OK.";
	}

	std::string visualizaEventosSemana(void){
		std::string resposta;
		for(int day = 0; day < 7; day++){
			resposta += (dias[day].mostraNomeDia() + "\n");
			for (int hour = 0; hour < 12; hour++) {
				if(dias[day].mostraEvento(hour) != ""){
					resposta += (std::to_string(2*hour) + "h até " + std::to_string((2*hour)+2) + "h: " + dias[day].mostraEvento(hour) + "\n");
				}
			}
		}
		std::cout<<resposta;
		return "OK.";
	}

	std::string mudaEvento(Autenticador& autenticador, std::string token, std::string novoEvento, int diaDesejado, int horario){
		if (autenticador.getToken() == token){
			dias[diaDesejado].mudaEvento(autenticador, token, novoEvento, horario);
			return "Evento alterado com sucesso.";
		}
		else{
			return "Algo de errado aconteceu.";
		}
	}
};

class Sala{
private:
	Semana semanas[20];

public:
	Sala(){
		for(int i = 0; i < 20; i++){
			semanas[i] = Semana();
		}
	}

	std::string visualizaEventosDia(int diaDesejado, int semanaDesejada){
		semanas[semanaDesejada].visualizaEventosDia(diaDesejado);
		std::cout<<"\n";
		return "OK.";
	}

	std::string visualizaEventosSemana(int semanaDesejada){
		std::cout<<"SEMANA " + std::to_string(semanaDesejada)<<std::endl;
		semanas[semanaDesejada].visualizaEventosSemana();
		std::cout<<"\n";
		return "OK.";
	}
	std::string mudaEvento(Autenticador& autenticador, std::string token, std::string novoEvento, int semanaDesejada, int diaDesejado, int horario){
		return semanas[semanaDesejada].mudaEvento(autenticador, token, novoEvento, diaDesejado, horario);
	}
	std::string mudaEventoRecorrente(Autenticador& autenticador, std::string token, std::string novoEvento, int semanaInicialDesejada, int SemanaFinalDesejada,int diaDesejado, int horario){
		for (int semanaAtual = semanaInicialDesejada; semanaAtual < SemanaFinalDesejada; semanaAtual++){
			semanas[semanaAtual].mudaEvento(autenticador, token, novoEvento, diaDesejado, horario);
		}
		return semanas[SemanaFinalDesejada].mudaEvento(autenticador, token, novoEvento, diaDesejado, horario);
	}
	//Mudar para leitura de jsons
};

class Laboratorio{
private:
	Autenticador autenticador;
	Gerenciador gerenciador;
	Sala salas[3];

public:
	Laboratorio(){
		autenticador = Autenticador("Padrão", 1);
		gerenciador = Gerenciador();
		for (int i = 0; i < 3; i++){
			salas[i] = Sala();
		}
	}
	std::string visualizaEventosDia(){
		for (int salaAtual = 0; salaAtual < 3; salaAtual++){
			std::cout<<"SALA " + std::to_string(salaAtual)<<std::endl;
			salas[salaAtual].visualizaEventosDia(0,0);
		}
		return "OK.";
	}

	std::string visualizaEventosSemana(int salaDesejada, int semanaDesejada){
		return salas[salaDesejada].visualizaEventosSemana(semanaDesejada);
	}

	std::string mudaEvento(std::string novoEvento, int semanaDesejada, int diaDesejado, int horario, int salaDesejada){
		return salas[salaDesejada].mudaEvento(autenticador, autenticador.getToken(), novoEvento, semanaDesejada, diaDesejado, horario);
	}

	std::string mudaEventoRecorrente(std::string novoEvento, int semanaInicialDesejada, int SemanaFinalDesejada,int diaDesejado, int horario, int salaDesejada){
		return salas[salaDesejada].mudaEventoRecorrente(autenticador, autenticador.getToken(), novoEvento, semanaInicialDesejada, SemanaFinalDesejada, diaDesejado, horario);
	}

};

/*
class Sala{
	private:
		eventosRecorrentes[];
		eventosUnicos[];



	public:
		std::string adicionaEvento(Autenticador& autenticador, std::string token, std::string novoEvento, int diaDesejado, int horario){
			if (autenticador.getToken() == token){
				dias[diaDesejado].mudaEvento(autenticador, token, novoEvento, horario);
				std::cout<<dias[diaDesejado].mostraEvento(horario)<<std::endl;
				return "Evento alterado com sucesso.";
			}
			else{
				return "Algo de errado aconteceu.";
			}
		}


		std::string visualizaEventos(void){
			std::string resposta;
			for(int day = 0; day < 7; day++){
				resposta += (dias[day].mostraNomeDia() + "\n");
				for (int hour = 0; hour < 12; hour++) {
					if(dias[day].mostraEvento(hour) != ""){
						resposta += (std::to_string(2*hour) + "h até " + std::to_string((2*hour)+2) + "h: " + dias[day].mostraEvento(hour) + "\n");
					}
				}
			}
			std::cout<<resposta;
			return "OK.";
		}
}

*/
