	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM excl2 */
;
		;
		;
		;
		
	case 5: // STATE 13
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* CLAIM excl1 */
;
		
	case 6: // STATE 1
		goto R999;

	case 7: // STATE 10
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* CLAIM excl0 */
;
		
	case 8: // STATE 1
		goto R999;

	case 9: // STATE 10
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC c */

	case 10: // STATE 1
		;
		_m = unsend(now.mychan);
		;
		goto R999;

	case 11: // STATE 5
		;
		_m = unsend(now.mychan);
		;
		goto R999;

	case 12: // STATE 9
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC p */

	case 13: // STATE 5
		;
		XX = 1;
		unrecv(now.mychan, XX-1, 0, 2, 1);
		;
		;
		goto R999;

	case 14: // STATE 9
		;
		XX = 1;
		unrecv(now.mychan, XX-1, 0, 1, 1);
		;
		;
		goto R999;

	case 15: // STATE 13
		;
		p_restor(II);
		;
		;
		goto R999;
	}

