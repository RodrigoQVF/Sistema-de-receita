# Sistema-de-receita
Sistema de receita desenvolvido em C que possibilita o usuário criar, modificar e excluir receitas<br>

#Funcionamento

O sistema funciona com um menu com 4 opções para criar, mostrar, editar e excluir as receitas no meio da execução do programa<br>
1 - cadastrar receita <br>

Para o cadastramento de receitas é necessário o usuário providênciar o nome da receita, quantidade de ingredientes e os ingredientes da receita.<br>
após isso, a tela apresentará que a receita foi cadastrada com sucesso!<br>

2 - Mostrar receitas cadastradas<br>

Para a exibição das receitas cadastradas é necessário pelo menos haver um ou mais cadastros de receitas feitas.<br>
A exibicação mostra o Id da receita, nome da receita e os ingredientes cadastrados de cada receita já feita.<br>

3 - Editar receita cadastrada<br>

Para a edição das receitas cadastradas é necessário pelo menos haver um ou mais cadastros de receitas feitas.<br>
É necessário providênciar o ID da receita que deseja editar, caso não tenha uma receita cadastrada com esse ID, o aplicativo exibirá que não existe receita com o Id mencionado.<br>

4 - Excluir receita cadastrada<br>

Para a exclusão de receita cadastrada, é necessário pelo menos haver um ou mais cadadstros de receitas feitas.<br>
É necessário o usuário providênciar o ID da receita que deseja excluir, caso não tenha uma receita cadastrada com esse ID, o aplicativo exibira que não existe receita com o Id mencionado.<br>

NA FINALIZAÇÃO DO PROGRAMA, ELE IRÁ CRIAR UM ARQUIVO DE TEXTO CHAMADO "receitas" QUE HAVERÁ TODAS AS RECEITAS CADASTRADAS DURANTE A EXECUÇÃO DO PROGRAMA.<BR>
APARTIR DO MOMENTO QUE O PROGRAMA É FINALIZADO, NÃO É MAIS POSSÍVEL EDITAR O ARQUIVO DE TEXTO OU MANIPULAR A RECEITA CADASTRADA QUE ESTÁ SALVADA NO ARQUIVO DE TEXTO<BR>
O ARQUIVO DE TEXTO SERÁ SOBREESCREVIDO CASO VOCÊ EXECUTE E CRIE UMA NOVA RECEITA SE O ARQUIVO DE TEXTO ESTIVER NA MESMA PASTA DO ARQUIVO "main.c".
