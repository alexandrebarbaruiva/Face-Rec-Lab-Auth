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
	* Construtor de autenticador vazio, lê de JSON.
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
	std::string mudaSenha(std::string novaSenha, std::string antigaSenha){
		if (senha == antigaSenha and id != -1){
			senha = novaSenha;
			return "Senha mudada com sucesso.";
		}
		else if (id == -1) {
			return "Usuário não registrado adequadamente.";
		}
		else{
			return "Senha errada, tente novamente.";
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
* @brief Classe principal, comunica com gerenciador e autenticador
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
	//TODO: fotos[]
public:
	//TODO: para ler de JSON
    Usuario(){
		nome = "";
	    sobrenome = "";
		cpf = "";
	    id = -1;
	}
	Usuario(std::string novoNome, std::string novoSobrenome, std::string novoCPF, int novoTipo){
		nome = novoNome;
	    sobrenome = novoSobrenome;
		cpf = novoCPF;
		id = 1;
		tipo = novoTipo;
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
	int requisitarAcesso(Laboratorio& laboratorio, int salaDesejada, int horarioDesejado);
};

/** @brief Classe responsável por conter todos os eventos do laboratório.
*
* Eventos são aulas, palestras, limpezas, manutenções, etc.
*
*/
class Evento{
private:
	std::string nome;
	std::string cpf[20];
	std::string proposito;
	std::string reservador;
	//TODO: adicionar nomeDoReservador (deve ser nome ou id? requisito: possuir tipo palestrante, professor ou funcionario)
public:
	//TODO: para ler de JSON
	Evento(){
		nome = "";
		proposito = "";
		reservador = "";
		for(int i = 0; i < 20; i++){
			cpf[i] = "";
		}
	}
	Evento(std::string novoNome, std::string novoProposito, std::string novoReservador){
		nome = novoNome;
		proposito = novoProposito;
		reservador = novoReservador;
		for(int i = 0; i < 20; i++){
			cpf[i] = "";
		}
	}
	std::string removeEvento(){
		nome = "";
		proposito = "";
		reservador = "";
		for(int i = 0; i < 20; i++){
			cpf[i] = "";
		}
		return "Evento removido com sucesso.";
	}
	void setNomeEvento(std::string novoNome){
		nome = novoNome;
	}
	std::string getNomeEvento(){
		return nome;
	}
	std::string adicionaProposito(std::string novoProposito){
		proposito = novoProposito;
		return "Propósito adicionado com sucesso.";
	}
	std::string getProposito(){
		return proposito;
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
	std::string removeParticipante(std::string cpfParticipante){
		for(int vaga = 0; vaga < 20; vaga++){
			if(cpf[vaga] == cpfParticipante){
				cpf[vaga] = "";
				return "Participante removido com sucesso. Há " + std::to_string(20-vaga) + " vagas disponíveis.";
			}
		}
		return "Participante não encontrado.";
	}
	std::string verificaParticipante(std::string participanteVerificado){
		for (int i = 0; i < 20; i++){
			if(cpf[i] == participanteVerificado){
				return "Participante encontra-se registrado no evento.";
			}
		}
		return "Participante não registrado no evento.";
	}
};

class Dia{
public:
	std::string nome;
	Evento eventos[12];
	//Horários disponíveis para eventos =	{0,2,4,6,8,10,12,14,16,18,20,22}

	Dia(){
		nome = "Segunda";
	}
	Dia(std::string nomeDia){
		nome = nomeDia;
		for(int i = 0; i < 12; i++){
			eventos[i] = Evento();
		}
	}
	std::string mudaEvento(Autenticador& autenticador, std::string token, Evento novoEvento, int horario){
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
		return eventos[horario].getNomeEvento();
	}
	std::string mostraNomeDia(){
		return nome;
	}
	std::string verificaParticipante(std::string participanteVerificado, int horarioDesejado){
		horarioDesejado = horarioDesejado/2;
		return eventos[horarioDesejado].verificaParticipante(participanteVerificado);
	}
};

class Semana{
public:
	Dia dias[7];

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
	std::string mudaEvento(Autenticador& autenticador, std::string token, Evento& novoEvento, int diaDesejado, int horario){
		if (autenticador.getToken() == token){
			dias[diaDesejado].mudaEvento(autenticador, token, novoEvento, horario);
			return "Evento alterado com sucesso.";
		}
		else{
			return "Algo de errado aconteceu.";
		}
	}
	std::string verificaParticipante(std::string participanteVerificado, int horarioDesejado){
		return dias[0].verificaParticipante(participanteVerificado, horarioDesejado);
	}
};

class Sala{
public:
	Semana semanas[20];

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
	std::string mudaEvento(Autenticador& autenticador, std::string token, Evento& novoEvento, int semanaDesejada, int diaDesejado, int horario){
		return semanas[semanaDesejada].mudaEvento(autenticador, token, novoEvento, diaDesejado, horario);
	}
	std::string mudaEventoRecorrente(Autenticador& autenticador, std::string token, Evento& novoEvento, int semanaInicialDesejada, int SemanaFinalDesejada,int diaDesejado, int horario){
		for (int semanaAtual = semanaInicialDesejada; semanaAtual < SemanaFinalDesejada; semanaAtual++){
			semanas[semanaAtual].mudaEvento(autenticador, token, novoEvento, diaDesejado, horario);
		}
		return semanas[SemanaFinalDesejada].mudaEvento(autenticador, token, novoEvento, diaDesejado, horario);
	}
	std::string verificaParticipante(std::string participanteVerificado, int horarioDesejado){
		return semanas[0].verificaParticipante(participanteVerificado, horarioDesejado);
	}
	//Mudar para leitura de jsons
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
	//FIXME: melhorar permissão de acesso
	/** @brief Permite acesso às salas e ao laboratório
	* 0: Sala 1
	* 1: Sala 2
	* 2: Sala 3
	*/
	int permitirAcesso(Usuario& usuario, Sala& salaDesejada, int sala, int horarioDesejado) {
		if(salaDesejada.verificaParticipante(usuario.getCPF(), horarioDesejado) == "Participante encontra-se registrado no evento."){
			std::cout<<(usuario.getNome() + " possui acesso, sala "+ std::to_string(sala) +" liberada.")<<std::endl;
			return sala;
		}
		else{
			std::cout<<(usuario.getNome() + " não possui acesso. Favor procurar responsáveis.")<<std::endl;
			return -1;
		}
	}
};

class Laboratorio{
public:
	Autenticador autenticador;
	Gerenciador gerenciador;
	Sala salas[3];

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
	std::string mudaEvento(Evento& novoEvento, int semanaDesejada, int diaDesejado, int horario, int salaDesejada){
		return salas[salaDesejada].mudaEvento(autenticador, autenticador.getToken(), novoEvento, semanaDesejada, diaDesejado, horario);
	}
	std::string mudaEventoRecorrente(Evento& novoEvento, int semanaInicialDesejada, int SemanaFinalDesejada,int diaDesejado, int horario, int salaDesejada){
		return salas[salaDesejada].mudaEventoRecorrente(autenticador, autenticador.getToken(), novoEvento, semanaInicialDesejada, SemanaFinalDesejada, diaDesejado, horario);
	}
	int requisitarAcesso(Usuario& usuario, int salaDesejada, int horarioDesejado){
		return gerenciador.permitirAcesso(usuario, salas[salaDesejada], salaDesejada, horarioDesejado);
	}
};

int Usuario::requisitarAcesso(Laboratorio& laboratorio, int salaDesejada, int horarioDesejado){
	return laboratorio.requisitarAcesso(*this, salaDesejada, horarioDesejado);
}
