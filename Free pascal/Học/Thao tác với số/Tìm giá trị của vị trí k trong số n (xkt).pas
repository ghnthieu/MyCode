Program bai2;
uses crt;
var n:qword;
    k:byte;
procedure nhap(var n:qword; var k:byte);
begin
  write('Nhap so N: ');readln(n);
  write('Nhap so K: ');readln(k);
end;
procedure in_ra(n:qword;k:byte);
var s:string;
begin
  str(n,s);
  if (k>length(s)) or (k<=0) then
    writeln('-1')
  else
    write('Vi tri cua ',k,' trong ',n,' la: ',s[k]);
end;
Begin
  clrscr;
  nhap(n,k);
  in_ra(n,k);
  readln
End.