-module(insertionsort).
-export([naive/1,efficient/1,efficientInsert/2]).

%% Naive implementation.
naiveInsert(Head,Tail) ->
        [X || X <- Tail, Head > X] ++ [Head] ++ [X || X <- Tail, Head =< X].

naive([]) ->
        [];
naive([Head|Tail]) ->
        naiveInsert(Head,naive(Tail)).

%% Efficient implementation.
efficientInsert(Key,[]) ->
        [Key];
efficientInsert(Key,List) ->
        [Head|Tail] = List,
        case Key =< Head of
                true ->
                        [Key|List];
                false ->
                        [Head|efficientInsert(Key,Tail)]
        end.

%% Get this error from efficient implementation of insertion sort.
%% ** exception error: no function clause matching lists:foldr(naiveInsert,[],[]) (lists.erl, line 1279)
%%      in function  lists:foldr/3 (lists.erl, line 1280)
efficient(List) ->
        lists:foldr(efficientInsert,[],List).
