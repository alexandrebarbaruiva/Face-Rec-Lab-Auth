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
