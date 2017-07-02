class Autenticador{
private:
	std::string nome;
	std::string senha; //para pedir outro token e acessar outras infos
	std::string token; //para fazer reserva
	int id;
public:
	Autenticador()
	Autenticador(std::string novoNome, int novoId)
	std::string getNome(void)
	int getId(void)
	std::string mudaSenha(std::string novaSenha, std::string antigaSenha)
	std::string geradorToken(void)
	std::string getToken(void)
};

class Evento{
private:
	std::string nome;
	std::string cpf[20];
	std::string proposito;
	std::string reservador;

public:
	Evento()
	Evento(std::string novoNome, std::string novoProposito, std::string novoReservador)
	---> Evento(Evento& eventoNovo)
	std::string removeEvento()
	void setNomeEvento(std::string novoNome)
	std::string getNomeEvento()
	std::string adicionaProposito(std::string novoProposito)
	std::string getProposito()
	std::string adicionaParticipante(std::string cpfParticipante)
	std::string removeParticipante(std::string cpfParticipante)
	std::string verificaParticipante(std::string participanteVerificado)
};

class Dia{
public:
	std::string nome;
	Evento eventos[12];
	//Horários disponíveis para eventos =	{0,2,4,6,8,10,12,14,16,18,20,22}

	Dia()
	Dia(std::string nomeDia)
	std::string mudaEvento(Autenticador& autenticador, std::string token, Evento novoEvento, int horario)
	std::string mostraEvento(int horario)
	std::string mostraNomeDia()
	std::string verificaParticipante(std::string participanteVerificado, int horarioDesejado)
};

class Semana{
public:
	Dia dias[7];

	Semana()
	std::string visualizaEventosDia(int diaDesejado)
	std::string visualizaEventosSemana(void)
	std::string mudaEvento(Autenticador& autenticador, std::string token, Evento& novoEvento, int diaDesejado, int horario)
	std::string verificaParticipante(std::string participanteVerificado, int horarioDesejado)
};

class Sala{
public:
	Semana semanas[20];

	Sala()
	std::string visualizaEventosDia(int diaDesejado, int semanaDesejada)
	std::string visualizaEventosSemana(int semanaDesejada)
	std::string mudaEvento(Autenticador& autenticador, std::string token, Evento& novoEvento, int semanaDesejada, int diaDesejado, int horario)
	std::string mudaEventoRecorrente(Autenticador& autenticador, std::string token, Evento& novoEvento, int semanaInicialDesejada, int SemanaFinalDesejada,int diaDesejado, int horario)
	std::string verificaParticipante(std::string participanteVerificado, int horarioDesejado)
};

class Usuario{
private:
	std::string nome;
	std::string sobrenome;
	std::string cpf;
	std::string matricula;
	int id;
	int tipo;

public:
    Usuario()
	Usuario(std::string novoNome, std::string novoSobrenome, std::string novoCPF, int novoTipo)
	std::string getNome(void)
	std::string getSobrenome(void)
	std::string getCPF(void)
	int getId(void)
	std::string pedirReserva(Autenticador& autenticador, Evento& eventoNovo, int horarioDesejado)
	int requisitarAcesso(Laboratorio& laboratorio, int salaDesejada, int horarioDesejado);
};

class Gerenciador{
public:
	Gerenciador(){}
	int permitirAcesso(Usuario& usuario, Sala& salaDesejada, int sala, int horarioDesejado)
};

class Laboratorio{
public:
	Autenticador autenticador;
	Gerenciador gerenciador;
	Sala salas[3];

	Laboratorio()
	std::string visualizaEventosDia()
	std::string visualizaEventosSemana(int salaDesejada, int semanaDesejada)
	std::string mudaEvento(Evento& novoEvento, int semanaDesejada, int diaDesejado, int horario, int salaDesejada) //add ou modifica evento
	std::string mudaEventoRecorrente(Evento& novoEvento, int semanaInicialDesejada, int SemanaFinalDesejada,int diaDesejado, int horario, int salaDesejada)
	int requisitarAcesso(Usuario& usuario, int salaDesejada, int horarioDesejado)
};

int requisitarAcesso(Laboratorio& laboratorio, int salaDesejada, int horarioDesejado)
