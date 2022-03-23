package sgh;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.ArrayList;

public class Paciente extends Pessoa implements Serializable {

	public Paciente() {
		super();
	}

	private ArrayList<ProfissionalSaude> profissional = new ArrayList<>();
	private LocalDateTime dataEntrada;
	private LocalTime horarioEntrada;
	private LocalDateTime dataSaida;
	private boolean internado;
	private String problemaSaude;
	private LocalTime horarioClassificacao;
	private String classificacaoRisco;

	public LocalDateTime getDataEntrada() {
		return dataEntrada;
	}

	public void setDataEntrada(LocalDateTime dataEntrada) {
		this.dataEntrada = dataEntrada;
	}

	public LocalTime getHorarioEntrada() {
		return horarioEntrada;
	}

	public void setHorarioEntrada(LocalTime horarioEntrada) {
		this.horarioEntrada = horarioEntrada;
	}

	public LocalDateTime getDataSaida() {
		return dataSaida;
	}

	public void setDataSaida(LocalDateTime dataSaida) {
		this.dataSaida = dataSaida;
	}

	public boolean isInternado() {
		return internado;
	}

	public void adicionaProfissional(ProfissionalSaude p) {
		profissional.add(p);

	}

	public ProfissionalSaude getProfissional() {
		for (ProfissionalSaude i : profissional) {
			return i;
		}
		return null;
	}

	public ArrayList<ProfissionalSaude> getProfissional1() {
		return profissional;
	}

	public void setInternado(boolean internado) {
		this.internado = internado;
	}

	public String getProblemaSaude() {
		return problemaSaude;
	}

	public void setProblemaSaude(String problemaSaude) {
		this.problemaSaude = problemaSaude;
	}

	public LocalTime getHorarioClassificacao() {
		return horarioClassificacao;
	}

	public void setHorarioClassificacao() {
		this.horarioClassificacao = LocalTime.now();
	}

	public String getClassificacaoRisco() {
		return classificacaoRisco;
	}

	public void setClassificacaoRisco(String classificacaoRisco) {
		this.classificacaoRisco = classificacaoRisco;
	}

	public StringBuilder profissionais() {
		String a = "";

		StringBuilder strBuilder = new StringBuilder(a);

		for (ProfissionalSaude p : profissional) {

			strBuilder.append(p.toString());

		}

		return strBuilder;

	}

	public String toString() {
		return "\nNome: " + super.getNome() + "\n" + "Data de entrada: " + dataEntrada + "\nData de Sa�da: " + dataSaida
				+ "\nFicou internado: " + internado + "\nProblema de Sa�de: " + problemaSaude
				+ "\nHora da classifica��o do risco: " + horarioClassificacao + "\nClassificacao do Risco: "
				+ classificacaoRisco + "\n" + profissionais();
	}

}
