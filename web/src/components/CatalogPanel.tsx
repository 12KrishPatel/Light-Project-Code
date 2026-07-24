import { memo, useMemo } from "react";
import { catalog, categories } from "../catalog";
import type { Design } from "../types";
import { CatalogThumb } from "./CatalogThumb";

type Props = {
  activeCategory: string;
  selectedId: string | null;
  onCategoryChange: (category: string) => void;
  onSelect: (design: Design) => void;
};

export const CatalogPanel = memo(function CatalogPanel({
  activeCategory,
  selectedId,
  onCategoryChange,
  onSelect,
}: Props) {
  const designs = useMemo(
    () =>
      activeCategory === "All"
        ? catalog
        : catalog.filter((d) => d.category === activeCategory),
    [activeCategory]
  );

  return (
    <aside className="catalog">
      <header className="catalog__header">
        <h2>Catalog</h2>
        <p>{catalog.length} designs ready to load</p>
      </header>

      <div className="catalog__filters" role="tablist" aria-label="Categories">
        {categories.map((category) => (
          <button
            key={category}
            type="button"
            role="tab"
            aria-selected={activeCategory === category}
            className={activeCategory === category ? "chip chip--active" : "chip"}
            onClick={() => onCategoryChange(category)}
          >
            {category}
          </button>
        ))}
      </div>

      <ul className="catalog__list">
        {designs.map((design) => (
          <li key={design.id}>
            <button
              type="button"
              className={
                selectedId === design.id
                  ? "catalog__item catalog__item--selected"
                  : "catalog__item"
              }
              onClick={() => onSelect(design)}
            >
              <CatalogThumb
                pixels={design.pixels}
                label={`${design.name} preview`}
                className="catalog__preview"
              />
              <span className="catalog__meta">
                <strong>{design.name}</strong>
                <em>{design.category}</em>
              </span>
            </button>
          </li>
        ))}
      </ul>
    </aside>
  );
});
