class TestBitAnd {
    public static void main (String[] args){
        {if ( true & false ) {
            System.out.println(0);
        }else{
            System.out.println(1);
        }

        if ( true & true ) {
            System.out.println(1);
        }else{
            System.out.println(0);
        }

        if ( false & false ) {
            System.out.println(0);
        }else{
            System.out.println(1);
        }
        
        if ( (5 & 6) == 4 ) {
            System.out.println(1);
        }else{
            System.out.println(0);
        }
    
        if ( (5 & 6) == 3 ) {
            System.out.println(0);
        }else{
            System.out.println(1);
        }}
    }
    
}
