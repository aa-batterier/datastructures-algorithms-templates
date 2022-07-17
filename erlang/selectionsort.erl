-module(selectionsort).
-export([naiveSort/1,efficientSort/1]).

%% Naive implementation.
naiveSort([]) ->
        [];
naiveSort(List) ->
        M = lists:min(List),
        [M | naiveSort(lists:delete(M,List))].

%% Efficient implementation.
split([],Minimum,Rest) ->
        [Minimum | efficientSort(Rest)];
split([Head|Tail],Minimum,Rest) ->
        case Head < Minimum of
                true ->
                        split(Tail,Head,[Minimum | Rest]);
                false ->
                        split(Tail,Minimum,[Head | Rest])
        end.

efficientSort([]) ->
        [];
efficientSort([Head|Tail]) ->
        split(Tail,Head,[]).
