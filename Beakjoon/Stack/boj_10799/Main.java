// [Beakjoon] 10799. 쇠막대기

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		String str = br.readLine();
		bw.append("" + solution(str));
		bw.flush();
	}
	
	static int solution(String str) {
		int pieceCnt = 0;
		int metals = 0;
		char lastRef = '\0';
		for(char ch : str.toCharArray()) {
			if(ch == '(') {
				++pieceCnt;
				++metals;
			} else { // ch == ')'
				if(lastRef == '(') { // 레이저
					--pieceCnt;
					--metals;
					pieceCnt += metals;
				} else { // lastRef == ')' // 쇠막대기의 끝
					--metals;
				}
			}
			lastRef = ch;
		}
		return pieceCnt;
	}
}
