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
