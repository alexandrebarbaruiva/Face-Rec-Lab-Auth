#define CATCH_CONFIG_MAIN
#include "others/catch.hpp"
#include "funcoes.cpp"
#include "classes.cpp"

/*TEST_CASE("Verificação de interface de linha de comando") {

    SECTION("Verificação de acesso", "[porta liberada], [autorização]"){
        REQUIRE(permitirAcesso(0, false) == -1 );
        REQUIRE(permitirAcesso(0, true) == 0 );
        REQUIRE(permitirAcesso(1, false) == -1 );
        REQUIRE(permitirAcesso(1, true) == 1 );
        REQUIRE(permitirAcesso(2, false) == -1 );
        REQUIRE(permitirAcesso(2, true) == 2 );
        REQUIRE(permitirAcesso(3, false) == -1 );
        REQUIRE(permitirAcesso(3, true) == 3 );
        REQUIRE(permitirAcesso(100, false) == -1 );
        REQUIRE(permitirAcesso(100, true) == -1 );
        std::cout<<"ACESSO OK"<<std::endl;
    }
}*/

TEST_CASE("Verificação de classes") {

    SECTION("Verifica classe Usuário", "[Informação]" ){
        std::cout<<"USUARIO BEGIN"<<std::endl;
        Usuario userTest = Usuario("Alexandre", "Augusto", "0124567890", 1);
        Autenticador authTest = Autenticador("Gabriel", 1);
        Gerenciador gerTest = Gerenciador();
        REQUIRE(userTest.getNome() == "Alexandre");
        REQUIRE(userTest.getSobrenome() == "Augusto");
        REQUIRE(userTest.getCPF() == "0124567890");
        REQUIRE(userTest.getId() == 1);
        REQUIRE(userTest.pedirReserva(authTest, authTest.getToken()) == "Reserva feita com sucesso.");
        REQUIRE(userTest.requisitarAcesso(gerTest, 0) == 0);
        REQUIRE(userTest.requisitarAcesso(gerTest, 1) == 1);
        REQUIRE(userTest.requisitarAcesso(gerTest, 2) == 2);
        REQUIRE(userTest.requisitarAcesso(gerTest, 3) == 3);

        Usuario otherTest = Usuario();
        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getSobrenome() == "");
        REQUIRE(otherTest.getCPF() == "");
        REQUIRE(otherTest.getId() == -1);
        std::cout<<"USUARIO OK\n"<<std::endl;
    }

    SECTION("Verifica classe Autenticador", "[Informação]"){
        std::cout<<"AUTENTICADOR BEGIN"<<std::endl;

        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(authTest.getNome() == "Gabriel");
        REQUIRE(authTest.getId() == 1);
        REQUIRE(authTest.mudaSenha("novaSenha","padrao5000") == "Senha mudada com sucesso.");
        REQUIRE(authTest.mudaSenha("outraSenha","padrao5000") == "Senha errada, tente novamente.");


        Autenticador otherTest = Autenticador();

        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getId() == -1);
        REQUIRE(otherTest.mudaSenha("novaSenha","") == "Usuário não registrado adequadamente.");
        std::cout<<"AUTENTICADOR OK\n"<<std::endl;
    }

    SECTION("Verifica classe Gerenciador", "[Informação]"){
        std::cout<<"GERENCIADOR BEGIN"<<std::endl;
        Gerenciador gerTest = Gerenciador();
        REQUIRE(gerTest.permitirAcesso(0, false) == -1);
        REQUIRE(gerTest.permitirAcesso(0, true) == 0);
        REQUIRE(gerTest.permitirAcesso(1, false) == -1);
        REQUIRE(gerTest.permitirAcesso(1, true) == 1);

        std::cout<<"GERENCIADOR OK\n"<<std::endl;
    }

    SECTION("Verifica classe Evento", "[Informação]"){
        std::cout<<"EVENTO BEGIN"<<std::endl;
        SECTION("Construtor com nome"){
            Evento eventoTest = Evento("Django Jam", "Palestra", "Django Unchained");
            REQUIRE(eventoTest.getNomeEvento() == "Django Jam");
            eventoTest.setNomeEvento("Jungle Jazz");
            REQUIRE(eventoTest.getNomeEvento() == "Jungle Jazz");
            REQUIRE(eventoTest.adicionaParticipante("01234567890") == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
            REQUIRE(eventoTest.removeParticipante("01234567890") == "Participante removido com sucesso. Há 20 vagas disponíveis.");
            REQUIRE(eventoTest.removeEvento() == "Evento removido com sucesso.");
            REQUIRE(eventoTest.adicionaProposito("Aula") == "Propósito adicionado com sucesso.");
            REQUIRE(eventoTest.getProposito() == "Aula");
        }
        SECTION("Construtor vazio"){
            Evento otherTest = Evento();
            REQUIRE(otherTest.getNomeEvento() == "");
            REQUIRE(otherTest.adicionaParticipante("01234567890") == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
        }
        std::cout<<"EVENTO OK\n"<<std::endl;
    }

    SECTION("Verifica classe Dia", "[Informação]"){
        std::cout<<"DIA BEGIN"<<std::endl;
        Dia diaTest = Dia();
        Autenticador authTest = Autenticador("Gabriel", 1);
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
        Sala salaTest = Sala();
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
        Laboratorio labTest = Laboratorio();
        Evento eventoTest = Evento("Seminário OpenCV", "Seminário", "Steve");
        Evento eventoTest2 = Evento("Aula TP1", "Aula", "Teófilo");

        REQUIRE(labTest.visualizaEventosDia() == "OK.");
        //(Nome do evento, semana, dia, horario, sala)
        REQUIRE(labTest.mudaEvento(eventoTest, 0, 3, 8, 0) == "Evento alterado com sucesso.");
        //(Nome do evento, semanaInicial, semanaFinal, dia, horario, sala)
        REQUIRE(labTest.mudaEventoRecorrente(eventoTest2, 0, 2, 1, 20, 0) == "Evento alterado com sucesso.");
        REQUIRE(labTest.mudaEventoRecorrente(eventoTest2, 0, 2, 3, 20, 0) == "Evento alterado com sucesso.");
        //(salaDesejada, semanaDesejada)
        REQUIRE(labTest.visualizaEventosSemana(0, 0) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(1, 0) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(0, 1) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(0, 2) == "OK.");

        std::cout<<"LABORATORIO OK\n"<<std::endl;
    }

}
