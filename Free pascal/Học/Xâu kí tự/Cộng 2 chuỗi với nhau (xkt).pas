Program xoa_kt;
uses crt;
var s1,s2,kq,s:string;
    a,b,i,c,d,sonho:integer;
begin
  clrscr;
  sonho:=0;
  kq:='';
  write('Nhap xau 1: ');readln(s1);
  write('Nhap xau 2: ');readln(s2);
  if length(s1)>length(s2) then
    for i:=1 to length(s1)-length(s2) do
      s2:='0'+s2;
  if length(s1)<length(s2) then
    for i:=1 to length(s2)-length(s1) do
      s1:='0'+s1;
  writeln(s1);
  writeln(s2);
  for i:=length(s1) downto 1 do
    begin
      val(s1[i],a);
      val(s2[i],b);
      c:=a+b+sonho;
      d:=c mod 10;
      str(d,s);
      kq:=s+kq;
      sonho:=c div 10;
    end;
  if sonho>0 then
    begin
      str(sonho,s);
      kq:=s+kq;
    end;
  write(kq);
  readln
End.