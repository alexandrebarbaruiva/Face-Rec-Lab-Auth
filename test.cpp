#define CATCH_CONFIG_MAIN
#include "others/catch.hpp"
#include "funcoes.cpp"
#include "classes.cpp"

/**
* @brief Unit Tests.
*
* 1. Criar teste;
* 2. Teste falhar;
* 3. Implementar código (mantém-se no 3 enquanto 4 não ocorrer);
* 4. Teste bem sucedido;
* 5. Voltar ao passo (1) até conclusão do projeto.
*
* Estrutura dos testes é a seguinte:
* 1. Inicializa testes com TEST_CASE;
* 2. Inicializa objetos para teste
* 3. Verifica funções de classes, separando diferentes classes com SECTION
* 4. No início e no final do teste de uma classe, imprime na linha de comando qual classe
* está sendo testada.
*
*/
TEST_CASE("Verificação de classes") {
    // Construtores gerados pela CLI
    Usuario userTest = Usuario("Alexandre", "Augusto", "0124567890", 1);
    Autenticador authTest = Autenticador("Gabriel", 1);
    Gerenciador gerTest = Gerenciador();
    Evento eventoTest = Evento("Django Jam", "Palestra", "Django Unchained");
    Dia diaTest = Dia();
    Laboratorio labTest = Laboratorio();
    Evento eventoTest1 = Evento("Seminário OpenCV", "Seminário", "Steve");
    Evento eventoTest2 = Evento("Aula TP1", "Aula", "Teófilo");
    Sala salaTest = Sala();

    // Construtores para leitura de JSON
    Usuario otherTest = Usuario();
    Autenticador otherAuthTest = Autenticador();
    Evento otherEventoTest = Evento();

    SECTION("Processo completo"){
        //Cria novo professor
        Usuario professor = Usuario("Alexandre", "Augusto", "11111111111", 3);
    }

    /**
    * Laboratorio possui 2 eventos
    *
    *
    */

    SECTION("Verifica classe Usuário", "[Informação]" ){
        std::cout<<"USUARIO BEGIN"<<std::endl;
        REQUIRE(userTest.getNome() == "Alexandre");
        REQUIRE(userTest.getSobrenome() == "Augusto");
        REQUIRE(userTest.getCPF() == "0124567890");
        REQUIRE(userTest.getId() == 1);
        REQUIRE(userTest.pedirReserva(authTest, authTest.getToken()) == "Reserva feita com sucesso.");
        REQUIRE(userTest.requisitarAcesso(labTest, 0, 8) == 0);
        REQUIRE(userTest.requisitarAcesso(labTest, 0, 10) == -1);

        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getSobrenome() == "");
        REQUIRE(otherTest.getCPF() == "");
        REQUIRE(otherTest.getId() == -1);
        std::cout<<"USUARIO OK\n"<<std::endl;
    }

    SECTION("Verifica classe Autenticador", "[Informação]"){
        std::cout<<"AUTENTICADOR BEGIN"<<std::endl;
        REQUIRE(authTest.getNome() == "Gabriel");
        REQUIRE(authTest.getId() == 1);
        REQUIRE(authTest.mudaSenha("novaSenha","padrao5000") == "Senha mudada com sucesso.");
        REQUIRE(authTest.mudaSenha("outraSenha","padrao5000") == "Senha errada, tente novamente.");

        REQUIRE(otherAuthTest.getNome() == "");
        REQUIRE(otherAuthTest.getId() == -1);
        REQUIRE(otherAuthTest.mudaSenha("novaSenha","") == "Usuário não registrado adequadamente.");
        std::cout<<"AUTENTICADOR OK\n"<<std::endl;
    }

    SECTION("Verifica classe Gerenciador", "[Informação]"){
        std::cout<<"GERENCIADOR BEGIN"<<std::endl;
        //(usuario, salaDesejada, salaNum, horarioDesejado)
        REQUIRE(gerTest.permitirAcesso(userTest, salaTest, 1, 0) == -1);
        //REQUIRE(gerTest.permitirAcesso(0, true) == 0);
        //REQUIRE(gerTest.permitirAcesso(1, false) == -1);
        //REQUIRE(gerTest.permitirAcesso(1, true) == 1);
        std::cout<<"GERENCIADOR OK\n"<<std::endl;
    }

    SECTION("Verifica classe Evento", "[Informação]"){
        std::cout<<"EVENTO BEGIN"<<std::endl;
        SECTION("Construtor com nome"){
            REQUIRE(eventoTest.getNomeEvento() == "Django Jam");
            eventoTest.setNomeEvento("Jungle Jazz");
            REQUIRE(eventoTest.getNomeEvento() == "Jungle Jazz");
            REQUIRE(eventoTest.adicionaParticipante("01234567890") == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
            REQUIRE(eventoTest.verificaParticipante("01234567890") == "Participante encontra-se registrado no evento.");
            REQUIRE(eventoTest.removeParticipante("01234567890") == "Participante removido com sucesso. Há 20 vagas disponíveis.");
            REQUIRE(eventoTest.removeEvento() == "Evento removido com sucesso.");
            REQUIRE(eventoTest.adicionaProposito("Aula") == "Propósito adicionado com sucesso.");
            REQUIRE(eventoTest.getProposito() == "Aula");
        }
        SECTION("Construtor vazio"){
            REQUIRE(otherEventoTest.getNomeEvento() == "");
            REQUIRE(otherEventoTest.adicionaParticipante("01234567890") == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
        }
        std::cout<<"EVENTO OK\n"<<std::endl;
    }

    SECTION("Verifica classe Dia", "[Informação]"){
        std::cout<<"DIA BEGIN"<<std::endl;
        Evento eventoTest = Evento("Novo evento", "Aula", "Alexandre");

        REQUIRE(diaTest.mudaEvento(authTest, authTest.getToken(), eventoTest, 0) == "Evento alterado com sucesso.");
        REQUIRE(diaTest.mostraEvento(0) == "Novo evento");
        REQUIRE(diaTest.mostraEvento(1) == "");
        REQUIRE(diaTest.mostraNomeDia() == "Segunda");

        std::cout<<"DIA OK\n"<<std::endl;
    }

    SECTION("Verifica classe Semana", "[Informação]"){
        std::cout<<"SEMANA BEGIN"<<std::endl;
        Semana semTest = Semana();
        Autenticador authTest = Autenticador("Gabriel", 1);
        Evento eventoTest = Evento("Django Jam", "Palestra", "Django Unchained");
        semTest.mudaEvento(authTest, authTest.getToken(), eventoTest, 0, 8);
        REQUIRE(semTest.visualizaEventosSemana() == "OK.");
        REQUIRE(semTest.visualizaEventosDia(0) == "OK.");
        std::cout<<"SEMANA OK\n"<<std::endl;

    }
    SECTION("Verifica classe Sala", "[Informação]"){
        std::cout<<"SALA BEGIN"<<std::endl;
        Autenticador authTest = Autenticador("Gabriel", 1);
        Evento eventoTest = Evento("Django Jam", "Palestra", "Django Unchained");
        Evento eventoTest2 = Evento("Aula TP1", "Aula", "Teófilo");

        REQUIRE(salaTest.visualizaEventosSemana(0) == "OK.");
        REQUIRE(salaTest.mudaEvento(authTest, authTest.getToken(), eventoTest, 0, 1, 8) == "Evento alterado com sucesso.");
        REQUIRE(salaTest.visualizaEventosSemana(0) == "OK.");
        REQUIRE(salaTest.mudaEventoRecorrente(authTest, authTest.getToken(), eventoTest2, 0, 2, 1, 20) == "Evento alterado com sucesso.");
        REQUIRE(salaTest.mudaEventoRecorrente(authTest, authTest.getToken(), eventoTest2, 0, 2, 3, 20) == "Evento alterado com sucesso.");
        REQUIRE(salaTest.visualizaEventosSemana(0) == "OK.");
        REQUIRE(salaTest.visualizaEventosSemana(1) == "OK.");
        REQUIRE(salaTest.visualizaEventosSemana(2) == "OK.");
        REQUIRE(salaTest.visualizaEventosSemana(3) == "OK.");
        std::cout<<"SALA OK\n"<<std::endl;
    }

    SECTION("Verifica classe Laboratorio", "[Informação]"){
        std::cout<<"LABORATORIO BEGIN"<<std::endl;

        REQUIRE(labTest.visualizaEventosDia() == "OK.");
        //(Nome do evento, semana, dia, horario, sala)
        REQUIRE(labTest.mudaEvento(eventoTest1, 0, 3, 8, 0) == "Evento alterado com sucesso.");
        //(Nome do evento, semanaInicial, semanaFinal, dia, horario, sala)
        REQUIRE(labTest.mudaEventoRecorrente(eventoTest2, 0, 2, 1, 20, 0) == "Evento alterado com sucesso.");
        REQUIRE(labTest.mudaEventoRecorrente(eventoTest2, 0, 2, 3, 20, 0) == "Evento alterado com sucesso.");
        //(salaDesejada, semanaDesejada)
        REQUIRE(labTest.visualizaEventosSemana(0, 0) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(1, 0) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(0, 1) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(0, 2) == "OK.");
        //REQUIRE(labTest.requisitarAcesso(0) == 0);//Adicionar cpf no input

        std::cout<<"LABORATORIO OK\n"<<std::endl;
    }

}
