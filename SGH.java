package sgh;

import java.io.Serializable;
import java.time.Duration;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

import javax.swing.JOptionPane;

public class SGH implements Serializable{
	GravaESalva g = new GravaESalva();
	
	private ArrayList<Paciente> generica = new ArrayList<>();
	private Map<String, ArrayList<Paciente>> pacientesClassificados = new HashMap<>();
	private ArrayList<ProfissionalSaude> profissionais = new ArrayList<>();
	private ArrayList<Paciente> pacientesNaoClassificados = new ArrayList<>();
	private ArrayList<Paciente> internados = new ArrayList<>();
	private String nomeProfissional;
	
	public Map<String, ArrayList<Paciente>> getPacientesClassificados(){
		return this.pacientesClassificados;
	}
	public SGH() {
		
		pacientesClassificados.put("VERMELHO", generica);
		pacientesClassificados.put("AMARELO", generica);
		pacientesClassificados.put("VERDE", generica);
		pacientesClassificados.put("AZUL", generica);
	}
	
	
	public ArrayList<Paciente> getGenerica() {
		return generica;
	}
	public void setGenerica(ArrayList<Paciente> generica) {
		this.generica = generica;
	}
	public ArrayList<ProfissionalSaude> getProfissionais() {
		return profissionais; 
	}
	public void setProfissionais(ArrayList<ProfissionalSaude> profissionais) {
		this.profissionais = profissionais;
	}
	public ArrayList<Paciente> getPacientesNaoClassificados() {
		return pacientesNaoClassificados;
	}
	public void setPacientesNaoClassificados(ArrayList<Paciente> pacientesNaoClassificados) {
		this.pacientesNaoClassificados = pacientesNaoClassificados;
	}
	public ArrayList<Paciente> getInternados() {
		return internados;
	}
	public void setInternados(ArrayList<Paciente> internados) {
		this.internados = internados;
	}
	public String getNomeProfissional() {
		return nomeProfissional;
	}
	public void setNomeProfissional(String nomeProfissional) {
		this.nomeProfissional = nomeProfissional;
	}
	public void setPacientesClassificados(Map<String, ArrayList<Paciente>> pacientesClassificados) {
		this.pacientesClassificados = pacientesClassificados;
	}
	
	public void gravar() {
		 g.grava(this.pacientesClassificados, this.profissionais, 
				 this.pacientesNaoClassificados, this.internados);	 
	}
	
	public void ler() {
		this.pacientesNaoClassificados = g.lerArray().get(0);
		this.profissionais = g.lerArray().get(1);
		this.internados = g.lerArray().get(2);
			
		System.out.println(this.pacientesNaoClassificados);
		System.out.println(this.profissionais);
		System.out.println(this.internados);
		
		this.pacientesClassificados = g.lerMapa().get(0);
		
	}

	public void adicionaProfissionalSaude() {
		ProfissionalSaude p = new ProfissionalSaude();

		JOptionPane.showMessageDialog(null, "SEJA BEM VINDO AO SOFTWARE DE CADASTRO!", "PROFISSIONAL DE SAUDE",
				JOptionPane.INFORMATION_MESSAGE);

		String itens[] = { "CRM", "COREN" };

		String valor = (String) JOptionPane.showInputDialog(null, "QUAL TIPO DE REGISTRO DESEJA CADASTRAR?",
				"CADASTRO PROF DE SAUDE", JOptionPane.INFORMATION_MESSAGE, null, itens, itens[0]);

		p.setTipoRegistro(valor);
		p.setNome(JOptionPane.showInputDialog("POR FAVOR, DIGITE O NOME DO PROFISSIONAL: "));
		p.setNumeroRegistro((JOptionPane.showInputDialog("POR FAVOR, DIGITE O NUMERO DE REGISTRO DO PROFISSIONAL: ")));

		p.setCpf(JOptionPane.showInputDialog("POR FAVOR, DIGITE O CPF DO PROFISSIONAL "));
		p.setDataNascimento(JOptionPane.showInputDialog("POR FAVOR, DIGITE A DATA DE NASCIMENTO DO PROFISSIONAL: "));

		JOptionPane.showMessageDialog(null, "VAMOS CADASTRAR O ENDERECO DO PROFISSIONAL", "PROFISSIONAL",
				JOptionPane.INFORMATION_MESSAGE);

		p.getEndereco().setBairro(JOptionPane.showInputDialog("POR FAVOR, DIGITE O BAIRRO DO PROFISSIONAL: "));
		p.getEndereco().setRua(JOptionPane.showInputDialog("POR FAVOR, DIGITE A RUA DO PROFISSIONAL: "));
		p.getEndereco().setCidade(JOptionPane.showInputDialog("POR FAVOR, DIGITE A CIDADE DO PROFISSIONAL: "));
		p.getEndereco().setnCasa(JOptionPane.showInputDialog("POR FAVOR, DIGITE O NUMERO DA CASA DO PROFISSIONAL: "));

		JOptionPane.showMessageDialog(null, "VAMOS CADASTRAR O CONTATO DO PROFISSIONAL", "DO PROFISSIONAL",
				JOptionPane.INFORMATION_MESSAGE);

		p.getContato().setEmail(JOptionPane.showInputDialog("POR FAVOR, DIGITE O EMAIL DO PROFISSIONAL: "));
		p.getContato().setTelefone(JOptionPane.showInputDialog("POR FAVOR, DIGITE O TELEFONE DO PROFISSIONAL: "));

		profissionais.add(p);

	}
	
	public void adicionaProfissionalDeSaudeTest(String tipoRegistro, String nome, String numeroRegistro,
			String cpf, String dataNascimento, String bairro, String rua, String cidade,
			String nCasa, String email, String telefone) {
		ProfissionalSaude p = new ProfissionalSaude();
		p.getContato().setEmail(email);
		p.getContato().setTelefone(telefone);
		p.getEndereco().setBairro(bairro);
		p.getEndereco().setCidade(cidade);
		p.getEndereco().setnCasa(nCasa);
		p.getEndereco().setRua(rua);
		
		p.setCpf(cpf);
		p.setDataNascimento(dataNascimento);
		p.setNome(nome);
		p.setTipoRegistro(tipoRegistro);
		p.setNumeroRegistro(numeroRegistro);
		profissionais.add(p);
	}

	public void adicionaPacienteRecepcionista() {
		Paciente paciente = new Paciente();

		JOptionPane.showMessageDialog(null, "SEJA BEM VINDO AO SOFTWARE DE CADASTRO!", "BOAS VINDAS",
				JOptionPane.INFORMATION_MESSAGE);

		paciente.setNome(JOptionPane.showInputDialog("POR FAVOR, DIGITE O NOME DO PACIENTE: "));
		paciente.setCpf(JOptionPane.showInputDialog("POR FAVOR, DIGITE O CPF DO PACIENTE "));
		paciente.setDataNascimento(JOptionPane.showInputDialog("POR FAVOR, DIGITE A DATA DE NASCIMENTO DO PACIENTE: "));
		paciente.setDataEntrada(LocalDateTime.now());
		JOptionPane.showMessageDialog(null, "VAMOS CADASTRAR O ENDERECO DO PACIENTE", "PACIENTE",
				JOptionPane.INFORMATION_MESSAGE);
		paciente.setHorarioEntrada(LocalTime.now());
		paciente.getEndereco().setBairro(JOptionPane.showInputDialog("POR FAVOR, DIGITE O BAIRRO DO PACIENTE: "));
		paciente.getEndereco().setRua(JOptionPane.showInputDialog("POR FAVOR, DIGITE A RUA DO PACIENTE: "));
		paciente.getEndereco().setCidade(JOptionPane.showInputDialog("POR FAVOR, DIGITE A CIDADE DO PACIENTE: "));
		paciente.getEndereco()
				.setnCasa(JOptionPane.showInputDialog("POR FAVOR, DIGITE O NUMERO DA CASA DO PACIENTE: "));

		JOptionPane.showMessageDialog(null, "VAMOS CADASTRAR O CONTATO DO PACIENTE", "PACIENTE",
				JOptionPane.INFORMATION_MESSAGE);

		paciente.getContato().setEmail(JOptionPane.showInputDialog("POR FAVOR, DIGITE O EMAIL DO PACIENTE: "));
		paciente.getContato().setTelefone(JOptionPane.showInputDialog("POR FAVOR, DIGITE O TELEFONE DO PACIENTE: "));

		pacientesNaoClassificados.add(paciente);
		for (Paciente i : pacientesNaoClassificados) {
			System.out.println(i.getNome());
		}
	}
	
	public void adicionaPacienteRecepcionistaTest(String nome, String cpf,
			String dataNascimento, LocalDateTime dataEntrada, LocalTime horarioEntrada,
			String bairro, String rua, String cidade,String nCasa, String email,
			String telefone) {
		
		Paciente p = new Paciente();
		
		p.getContato().setEmail(email);
		p.getContato().setTelefone(telefone);
		p.getEndereco().setBairro(bairro);
		p.getEndereco().setCidade(cidade);
		p.getEndereco().setnCasa(nCasa);
		p.getEndereco().setRua(rua);
		
		p.setNome(nome);
		p.setCpf(cpf);
		p.setDataEntrada(dataEntrada);
		p.setDataNascimento(dataNascimento);
		p.setHorarioEntrada(horarioEntrada);
		
		pacientesNaoClassificados.add(p);
		
	}

	public void chamadaDoMedico() {
		int condicao = 0;
		Paciente atendido1 = new Paciente();

		if ((!pacientesClassificados.get("VERMELHO").isEmpty()) && condicao != 1) {
			ArrayList<Paciente> p = pacientesClassificados.get("VERMELHO");
			Paciente atendido = p.get(0);
			atendido1 = atendido;
			pacientesClassificados.get("VERMELHO").remove(0);
			condicao = 1;

		} else if ((!pacientesClassificados.get("AMARELO").isEmpty()) && condicao != 1) {
			ArrayList<Paciente> p = pacientesClassificados.get("AMARELO");
			Paciente atendido = p.get(0);
			atendido1 = atendido;
			pacientesClassificados.get("AMARELO").remove(0);
			condicao = 1;
		} else if ((!pacientesClassificados.get("VERDE").isEmpty()) && condicao != 1) {
			ArrayList<Paciente> p = pacientesClassificados.get("VERDE");
			Paciente atendido = p.get(0);
			atendido1 = atendido;
			pacientesClassificados.get("VERDE").remove(0);
			condicao = 1;
		} else if ((!pacientesClassificados.get("AZUL").isEmpty()) && condicao != 1) {
			ArrayList<Paciente> p = pacientesClassificados.get("AZUL");
			Paciente atendido = p.get(0);
			atendido1 = atendido;
			pacientesClassificados.get("AZUL").remove(0);
			condicao = 1;
		}

		String problemaDeSaude = JOptionPane.showInputDialog("Qual o problema de sa�de?");

		atendido1.setProblemaSaude(problemaDeSaude);

		String itens[] = { "ALTA", "INTERNA��O" };

		String internaOuAlta = (String) JOptionPane.showInputDialog(null, "DESEJA INTERNAR OU DAR ALTA?",
				"CADASTRO PROF DE SAUDE", JOptionPane.INFORMATION_MESSAGE, null, itens, itens[0]);

		String nomeMedico = JOptionPane.showInputDialog("Digite o nome do m�dico: ");
		boolean cond = false;

		for (ProfissionalSaude prof : profissionais) {

			if (nomeMedico.equals(prof.getNome())) {

				atendido1.adicionaProfissional(prof);

				cond = true;
			}

		}

		if (cond == false) {
			JOptionPane.showMessageDialog(null, "MEDICO NAO EXISTE!", "TENTE OUTRA VEZ",
					JOptionPane.INFORMATION_MESSAGE);
			return;
		}

		if (internaOuAlta.equals("INTERNA��O")) {
			atendido1.setInternado(true);
			internados.add(atendido1);
			
			JOptionPane.showMessageDialog(null, "INTERNACAO PARA O PACIENTE: " + atendido1.toString(), "ALTA",
					JOptionPane.INFORMATION_MESSAGE);

		} else {

			atendido1.setDataSaida(LocalDateTime.now());
			JOptionPane.showMessageDialog(null, "ALTA PARA O PACIENTE: " + atendido1.toString(), "ALTA",
					JOptionPane.INFORMATION_MESSAGE);

		}

	}

	public void funcaoEnfermeiro() {
		JOptionPane.showMessageDialog(null, "SEJA BEM VINDO AO SOFTWARE DE CLASSIFICACAO DE RISCO!", "BOAS VINDAS",
				JOptionPane.INFORMATION_MESSAGE);
		boolean saiOuNao = false;

		while (true) {
			boolean c = false;

			String nomeProfissional1 = JOptionPane.showInputDialog("POR FAVOR, DIGITE O NOME DO PROFISSIONAL: ");
			this.nomeProfissional = nomeProfissional1;

			for (ProfissionalSaude i : profissionais) {
				if (i.getNome().contains(nomeProfissional1)) {
					c = true;
					break;
				}
			}

			if (c == true) {
				break;
			}

			JOptionPane.showMessageDialog(null, "VOCE ERROU, TENTE DE NOVO", "ERRO", JOptionPane.INFORMATION_MESSAGE);

			if (JOptionPane.showInputDialog("DESEJA PARAR DE TENTAR? S/N").equals("S")) {
				saiOuNao = true;
				break;
			}

		}

		if (saiOuNao == true) {
			return;

		}

		String nomePaciente = JOptionPane.showInputDialog("POR FAVOR, DIGITE O NOME DO PACIENTE NAO CLASSIFICADO: ");

		String itens[] = { "VERMELHO", "AMARELO", "VERDE", "AZUL" };

		String valor = (String) JOptionPane.showInputDialog(null, "QUAL TIPO DE CLASSIFICACAO?",
				"CADASTRO PROF DE SAUDE", JOptionPane.INFORMATION_MESSAGE, null, itens, itens[0]);

		for (Paciente i : pacientesNaoClassificados) {

			if (i.getNome().equals(nomePaciente)) {

				i.setClassificacaoRisco(valor);

				for (ProfissionalSaude p : profissionais) {

					if (p.getNome().equals(nomeProfissional)) {

						i.adicionaProfissional(p);
					}
				}

				int indice = pacientesNaoClassificados.indexOf(i);

				pacientesNaoClassificados.remove(indice);

				i.setHorarioClassificacao();

				if (valor.equals("VERMELHO")) {
					pacientesClassificados.get("VERMELHO").add(i);

				} else if (valor.equals("AZUL")) {
					pacientesClassificados.get("AZUL").add(i);

				} else if (valor.equals("VERDE")) {
					pacientesClassificados.get("VERDE").add(i);
				} else if (valor.equals("AMARELO")) {
					pacientesClassificados.get("AMARELO").add(i);
				}

			}
			break;
		}

	}

	public void tempoEspera() {
		String nomePaciente = JOptionPane.showInputDialog("POR FAVOR, DIGITE O NOME DO PACIENTE: ");

		ArrayList<Paciente> qualquer = new ArrayList<>();
		ArrayList<Paciente> qualquer1 = new ArrayList<>();
		
		for(Paciente p: pacientesNaoClassificados) {
			if (nomePaciente.equals(p.getNome())) {

				Duration duracao = Duration.between(p.getHorarioEntrada(), LocalTime.now());

				JOptionPane.showMessageDialog(null, "O PACIENTE EST� ESPERANDO H�: " + duracao.getSeconds() / 60.0

						+ " minutos", "ERRO", JOptionPane.INFORMATION_MESSAGE);
			}
		}
		
		for (Entry<String, ArrayList<Paciente>> pair : pacientesClassificados.entrySet()) {
			qualquer = pair.getValue();

		}

		for (Paciente i : qualquer) {
			System.out.println(i.getNome());
			if (nomePaciente.equals(i.getNome())) {

				Duration duracao = Duration.between(i.getHorarioClassificacao(), LocalTime.now());

				JOptionPane.showMessageDialog(null, "O PACIENTE EST� ESPERANDO H�: " + duracao.getSeconds() / 60.0

						+ " minutos", "ERRO", JOptionPane.INFORMATION_MESSAGE);

			}
		}

	}

	public void prontuario(Paciente p) {

		JOptionPane.showMessageDialog(null, p.toString(), "PRONTUARIO", JOptionPane.INFORMATION_MESSAGE);

	}

	public void prontuario() {
		String nomePaciente = JOptionPane.showInputDialog("POR FAVOR, DIGITE O NOME DO PACIENTE: ");

		ArrayList<Paciente> qualquer = new ArrayList<>();

		for (Entry<String, ArrayList<Paciente>> pair : pacientesClassificados.entrySet()) {
			qualquer = pair.getValue();
		}
		
		for (Paciente i : qualquer) {
			if (nomePaciente.equals(i.getNome())) {
				JOptionPane.showMessageDialog(null, i.toString(), "PRONTUARIO", JOptionPane.INFORMATION_MESSAGE);
			}
		}

	}
}