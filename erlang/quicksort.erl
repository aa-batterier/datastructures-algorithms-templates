-module(quicksort).
-export([naive/1,improved/1,efficient/1]).

%% Naive implementation.
naive([]) ->
        [];
naive([Pivot|Tail]) ->
        naive([X || X <- Tail, X =< Pivot]) ++ [Pivot] ++ naive([X || X <- Tail, X > Pivot]).

%% Improved implementation.
improved(List) ->
        Sort = fun Rec([],Sorted) ->
                               Sorted;
                   Rec([Pivot|Tail],Sorted) ->
                               Rec([X || X <- Tail, X =< Pivot],[Pivot|Rec([X || X <- Tail, X > Pivot],Sorted)])
               end,
        Sort(List,[]).

%% Efficient implementation.
qs([],Sorted) ->
        Sorted;
qs([Element],Sorted) ->
        [Element|Sorted];
qs([Pivot|Tail],Sorted) ->
        split(Pivot,Tail,[],[],Sorted).

split(Pivot,[],Lower,Upper,Sorted) ->
        qs(Lower,[Pivot|qs(Upper,Sorted)]);
split(Pivot,[Head|Tail],Lower,Upper,Sorted) ->
        case Head < Pivot of
                true ->
                        split(Pivot,Tail,[Head|Lower],Upper,Sorted);
                false ->
                        split(Pivot,Tail,Lower,[Head|Upper],Sorted)
        end.

efficient(List) ->
        qs(List,[]).
