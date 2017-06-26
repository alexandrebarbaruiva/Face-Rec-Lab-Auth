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
