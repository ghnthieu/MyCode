Program in_nguoc;
uses crt;
var s:string;
    i:integer;
begin
  clrscr;
  write('Nhap chuoi ky tu can doi cho: ');readln(s);
  for i:=length(s) downto 1 do
    write(s[i]);
  readln
end.
