package sgh;

import java.io.Serializable;

public class Contato implements Serializable{

	private String telefone;
	private String email;
	
	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String toString() {
		return "\nTelefone: " + this.telefone + "\nEmail" + this.email;
	}
}
