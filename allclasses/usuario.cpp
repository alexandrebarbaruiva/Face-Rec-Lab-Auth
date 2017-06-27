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
