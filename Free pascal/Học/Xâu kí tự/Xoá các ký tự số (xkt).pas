Program xoa_kt;
uses crt;
var s:string;
    i:integer;
begin
  clrscr;
  write('Nhap xau ki tu muon xoa: ');readln(s);
  for i:=length(s) downto 1 do
    if s[i] in['0'..'9'] then
      delete(s,i,1);
  while pos(#32#32,s)<>0 do
    delete(s,pos(#32#32,s),1);
  for i:=1 to length(s) do
    write(s[i]);
  readln
End.