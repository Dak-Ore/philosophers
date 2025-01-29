<h2>Description</h2>
<p>Le projet <strong>Philosophers</strong> est un exercice d'algorithmie et de gestion des threads visant à résoudre le <strong>problème des philosophes mangeurs</strong>. Il met en avant la gestion des <strong>threads</strong>, des <strong>mutexes</strong> et la <strong>synchronisation</strong> des accès aux ressources partagées.</p>

<h2>Objectifs</h2>
<ul>
    <li>Comprendre et implémenter la synchronisation des threads.</li>
    <li>Gérer la concurrence et éviter les conditions de course.</li>
    <li>Implémenter des mutex pour éviter les accès simultanés aux ressources partagées.</li>
    <li>Prévenir les problèmes de <strong>deadlock</strong>, <strong>starvation</strong> et <strong>data races</strong>.</li>
</ul>

<h2>Compilation</h2>
<p>Ce projet est écrit en <strong>C</strong> et doit être compilé avec <strong>pthread</strong>.</p>
<pre><code>make</code></pre>
<p>Cela génère un exécutable <code>philo</code>.</p>

<h2>Exécution</h2>
<p>Le programme s'exécute avec la commande suivante :</p>
<pre><code>./philo &lt;number_of_philosophers&gt; &lt;time_to_die&gt; &lt;time_to_eat&gt; &lt;time_to_sleep&gt; [number_of_times_each_philosopher_must_eat]</code></pre>

<h3>Arguments :</h3>
<ul>
    <li><strong>number_of_philosophers</strong> : Nombre total de philosophes et de fourchettes.</li>
    <li><strong>time_to_die</strong> : Temps (en ms) après lequel un philosophe meurt s’il ne mange pas.</li>
    <li><strong>time_to_eat</strong> : Temps (en ms) qu’un philosophe met pour manger.</li>
    <li><strong>time_to_sleep</strong> : Temps (en ms) qu’un philosophe met pour dormir.</li>
    <li><strong>number_of_times_each_philosopher_must_eat</strong> (optionnel) : Nombre de repas après lequel le programme s’arrête.</li>
</ul>

<h3>Exemple :</h3>
<pre><code>./philo 5 800 200 200</code></pre>

<h2>Fonctionnement</h2>
<p>Chaque philosophe :</p>
<ol>
    <li>Pense 🧠</li>
    <li>Prend une fourchette 🍴</li>
    <li>Prend une deuxième fourchette 🍴</li>
    <li>Mange 🍝</li>
    <li>Pose ses fourchettes 💤</li>
    <li>Dort 😴</li>
    <li>Recommence 🔁</li>
</ol>

<p>Le programme s’arrête si un philosophe meurt ou si tous ont mangé un nombre défini de fois (si l’argument optionnel est fourni).</p>

<h2>Précautions et Optimisations</h2>
<ul>
    <li>Utilisation des <strong>mutexes</strong> pour éviter les accès simultanés aux fourchettes.</li>
    <li>Vérification régulière du <strong>temps de vie</strong> des philosophes.</li>
    <li>Éviter les <strong>deadlocks</strong> en attribuant des stratégies adaptées (par exemple, alterner l’ordre de prise des fourchettes).</li>
</ul>

<h2>Ressources utiles</h2>
<ul>
    <li><a href="https://fr.wikipedia.org/wiki/Probl%C3%A8me_des_philosophes">Le problème des philosophes sur Wikipedia</a></li>
    <li><a href="https://man7.org/linux/man-pages/man7/pthreads.7.html">Documentation sur pthreads</a></li>
</ul>

<hr>
<p>Projet réalisé dans le cadre du cursus <strong>42</strong>. 🚀</p
