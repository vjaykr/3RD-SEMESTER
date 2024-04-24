
import java.time.LocalDate;
import java.time.Period;

public class age_converter {
    public static void main(String[] args) {
        calculate(2005,05 , 29);
    }

    

    public static void calculate(int year, int month, int day) {
        LocalDate dob= LocalDate.of(year,month,day);
        LocalDate curdate=LocalDate.now();

        Period date= Period.between(dob,curdate);
        System.out.printf("year %d month %d day %d",date.getYears(),date.getMonths(),date.getDays());
        
    }
}
