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
