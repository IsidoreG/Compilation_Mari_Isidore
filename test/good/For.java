class For {
    public static void main(String[] args) {
        System.out.println(new ForAux().f());
    }
}

class ForAux {
    public int f(){
        int i;
        int res;
        i = 0;
        res = 0;
        for (i = 0; i < 10; i = i + 1) {
            res = res + 2;
        }
        return res;
    }

}

