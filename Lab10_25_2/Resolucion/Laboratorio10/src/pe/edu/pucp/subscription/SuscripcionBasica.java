package pe.edu.pucp.subscription;

public class SuscripcionBasica extends Suscripcion {

    @Override
    public String getTipo() {
        return "BASICA";
    }

    @Override
    public double calcularPrecio() {
        return 50.00;
    }
}
