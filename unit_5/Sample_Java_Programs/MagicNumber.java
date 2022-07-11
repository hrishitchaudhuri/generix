public class MagicNumber<T extends Number> {
   private T value;
   public MagicNumber(T value) { this.value = value; }
   public boolean isMagic() { return value.intValue() == 9; }
   public String toString() { return "MagicNumber[value=" + value +"]"; }

   public static void main(String[] args) {
      MagicNumber<Double> n1 = new MagicNumber<>(9.9);
      System.out.println(n1);           //MagicNumber[value=9.9]
      System.out.println(n1.isMagic()); //true

      MagicNumber<Float> n2 = new MagicNumber<>(1.23f);
      System.out.println(n2);           //MagicNumber[value=1.23]
      System.out.println(n2.isMagic()); //false

      MagicNumber<Number> n3 = new MagicNumber<>(1);
      System.out.println(n3);           //MagicNumber[value=1]
      System.out.println(n3.isMagic()); //false

      //MagicNumber<String> n4 = new MagicNumber<>("hello");
      //error: type argument String is not within bounds of type-variable T
   }
}