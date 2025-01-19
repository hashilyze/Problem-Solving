// [Beakjoon] 4889. 안정적인 문자열

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		int no = 1;
		while(true) {
			String str = br.readLine();
			if(str.charAt(0) == '-') break;
			
			int cnt = 0;
			int opened = 0;
			for(char ch : str.toCharArray()) {
				if(ch == '{') {
					++opened;
				} else { // ch == '}'
					if(opened == 0) { // 닫힌 괄호와 매칭되는 열린괄호가 없으므로 변경
						++opened; 
						++cnt;
					} else { // 열린괄호와 닫힌괄호의 쌍 형성
						--opened; 
					}
				}
			}
			cnt += opened / 2; // 열린 괄호의 절반을 닫힌 괄호로 변경
			
			bw.append(String.format("%d. %d\n", no++, cnt));
		}
		bw.flush();
	}
}

