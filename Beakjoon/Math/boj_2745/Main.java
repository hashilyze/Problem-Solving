// [Beakjoon] 2745. 진법 변환
// https://www.acmicpc.net/problem/2745

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	
	public static void main(String[] args) throws IOException {
		// Input
		StringTokenizer st = new StringTokenizer(br.readLine());
		String N = st.nextToken();
		int B = Integer.parseInt(st.nextToken());
		
		// Solution
		int decimal = 0;
		for(char digit : N.toCharArray()) { 
			decimal = decimal * B + toDecimal(N.charAt(i));
		}
		
		// Output
		bw.append(Integer.toString(decimal));	
		bw.flush();
	}
	
	static int toDecimal(char digit) {
		if(Character.isDigit(digit)) return digit - '0';
		else return digit - 'A' + 10;
	}

}
