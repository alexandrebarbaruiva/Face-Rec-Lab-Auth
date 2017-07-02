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
