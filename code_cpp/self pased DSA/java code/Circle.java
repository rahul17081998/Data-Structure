public class Circle implements Shape{
    private double radius;


    public Circle(double radius){
        this.radius=radius;
    }


    public double getArea(){
        return 3.14*radius*radius;
    }

    public double getPerimeter(){
        return 2*3.14*radius;
    }

    public static void main(String[] args) {
        Circle circle1=new Circle(5);
        System.out.print(circle1.getArea());
        System.out.print(circle1.getPerimeter());
    }
}
