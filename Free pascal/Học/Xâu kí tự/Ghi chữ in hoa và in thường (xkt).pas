Program hoa_thuong;
uses crt;
var s:string;
    i,n:integer;
begin
  clrscr;
  write('Nhap chuoi ki tu muon ghi thuong (hoa): ');readln(s);
  writeln('Nhap 1 de ghi thuong, 2 de ghi hoa');
  write('Ban muon ghi thuong hay hoa: ');readln(n);
  case n of
    1:begin
        for i:=1 to length(s) do
          if s[i] in['A'..'Z'] then
            s[i]:=chr(ord(s[i])+32);
        for i:=1 to length(s) do
          write(s[i]);
      end;
    2:write(upcase(s));
  end;
  readln
End.