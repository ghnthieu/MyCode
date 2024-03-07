Program xoa_ktt;
uses crt;
var s:string;
    i:integer;
begin
  clrscr;
  write('Nhap chuoi ky tu can xoa:');readln(s);
  while s[1]=#32 do
    delete(s,1,1);
  while s[length(s)]=#32 do
    delete(s,length(s),1);
  while pos(#32#32,s)<>0 do
    delete(s,pos(#32#32,s),1);
  write(s);
  readln
end.
