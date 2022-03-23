package sgh;

import static org.junit.jupiter.api.Assertions.*;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

import org.junit.jupiter.api.Test;

class SGHTest {

	@Test
	void testClassificacoesEstaoSendoInseridas() {
		SGH sgh = new SGH();
		assertNotNull(sgh.getPacientesClassificados().get("VERMELHO"), "O MAPA DE CLASSIFICACOES NAO PODE SER NULO");
		assertTrue(!sgh.getPacientesClassificados().isEmpty());
		
	}
	@Test
	void testAdicionaProfissionalDeSaude() {
		SGH sgh = new SGH();
		sgh.adicionaProfissionalDeSaudeTest("CRM", "Marco Antonio", "2154-69",
				"10622154598", "30/02/1980", "Sucupíras", "Laranjeiras", "Itajaí",
				"25", "marco@bol.com", "3421-9966");
		assertNotNull(sgh.getProfissionais(), "O MAPA DE PROFISSIONAIS NAO PODE SER NULO");
		assertTrue(!sgh.getProfissionais().isEmpty());
	}
	
	@Test
	void testAdicionaPacienteRecepcionista(){
		SGH sgh = new SGH();
		
		LocalTime l = LocalTime.now();
		LocalDateTime local = LocalDateTime.now();
		
		sgh.adicionaPacienteRecepcionistaTest("Felipe Andrade", "10269365485", "20/09/82",
				local, l, "Laranjeiras", "Algarobas", "Sao Paulo", "85", "felipe@bol.com",
				"999886633");
		assertNotNull(sgh.getPacientesNaoClassificados(), "O ARRAY DE PACIENTES NAO PODE SER NULO");
		assertTrue(!sgh.getPacientesNaoClassificados().isEmpty());
	}

}
